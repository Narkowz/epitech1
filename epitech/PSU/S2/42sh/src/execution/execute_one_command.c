/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** execute_one_command.c
*/

#include <stdbool.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <errno.h>
#include "builtin.h"
#include "shell.h"
#include "macro.h"
#include "my.h"

static void check_status(shell_t *shell)
{
    int exit_status;

    exit_status = WTERMSIG(shell->ret);
    if (exit_status == SIGSEGV) {
        my_putstr("Segmentation fault\n", 2);
        shell->ret = 139;
    } else {
        exit_status = WEXITSTATUS(shell->ret);
        shell->ret = exit_status;
    }
}

void execute_command(shell_t *shell)
{
    char *copy = NULL;
    struct stat buff;

    copy = my_strdup(COMMAND->arr[0]);
    COMMAND->arr[0] = get_command(shell->env, COMMAND->arr[0]);
    if (COMMAND->arr[0] == NULL)
        err_exec(copy, ": Command not found.\n");
    if (access(COMMAND->arr[0], X_OK) == 0 &&
        stat(COMMAND->arr[0], &buff) == 0 &&
        S_ISREG(buff.st_mode) != 0) {
        execve(COMMAND->arr[0], COMMAND->arr, shell->env);
        if (errno == ENOEXEC)
            err_exec(copy, ": Exec format error. Wrong Architecture.\n");
    } else
        err_exec(copy, ": Permission denied.\n");
}

static void fork_command(shell_t *shell)
{
    struct rusage child_rusage;
    pid_t child_pid = fork();

    if (child_pid != 0) {
        wait4(child_pid, &shell->ret, 0, &child_rusage);
        check_status(shell);
    } else {
        execute_command(shell);
    }
}

command_t *handle_rright_or_drright(shell_t *shell, command_t *cpy, int index)
{
    int original = dup(STDOUT_FILENO);
    int fd;

    if (cpy->prev && cpy->prev->cmd) {
        fd = open_redirect(cpy->sep, cpy->prev->cmd);
        if (fd == -1) {
            shell->ret = 1;
            return cpy->prev->prev;
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        if (cpy->prev->sep == T_DRLEFT || cpy->prev->sep == T_RLEFT)
            return handle_rleft_or_drleft(shell, cpy->prev, index);
        execute_one_command(shell);
        dup2(original, STDOUT_FILENO);
        cpy = cpy->prev->prev;
    }
    return cpy;
}

command_t *handle_rleft_or_drleft(shell_t *shell, command_t *cpy, int index)
{
    int old_stdin = dup(STDIN_FILENO);
    int fd;

    if (cpy->prev && cpy->prev->cmd) {
        fd = open_redirect(cpy->sep, cpy->prev->cmd);
        if (fd == -1) {
            shell->ret = 1;
            return cpy->prev->prev;
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
        if (cpy->prev->sep == T_RRIGHT || cpy->prev->sep == T_DRRIGHT)
            return handle_rright_or_drright(shell, cpy->prev, index);
        execute_one_command(shell);
        dup2(old_stdin, STDIN_FILENO);
        cpy = cpy->prev->prev;
    }
    return cpy;
}

void execute_one_command(shell_t *shell)
{
    if (!COMMAND->arr || !COMMAND->arr[0] || strlen(COMMAND->arr[0]) == 0)
        return;
    if (builtin(shell))
        return;
    fork_command(shell);
}
