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
        printf("%d\n", shell->ret);
        shell->ret = 4;
    } else {
        printf("%d\n", shell->ret);
        exit_status = WEXITSTATUS(shell->ret);
        printf("%d\n", exit_status);
        shell->ret = exit_status;
    }
}

static void wait_child(pid_t child_pid, shell_t *shell)
{
    int status;
    int signal_num;

    waitpid(child_pid, &status, 0);
    signal_num = WTERMSIG(status);
    if (signal_num == SIGSEGV) {
        printf("Segmentation fault\n");
        shell->ret = 139;
    } else
        shell->ret = status;
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

void fork_command(shell_t *shell)
{
    pid_t child_pid = fork();

    if (child_pid != 0) {
        wait_child(child_pid, shell);
    } else {
        execute_command(shell);
        exit(1);
    }
}

command_t *handle_rright_or_drright(shell_t *shell, command_t *cpy, int index)
{
    int fd;

    if (cpy->prev && cpy->prev->cmd) {
        fd = open_redirect(cpy->sep, cpy->prev->cmd);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        execute_one_command(shell, NULL);
        dup2(get_original_stdout(), STDOUT_FILENO);
        cpy = cpy->prev->prev;
    }
    return cpy;
}

void execute_one_command(shell_t *shell, parser_t **cpy)
{
    if (!COMMAND->arr || !COMMAND->arr[0] || strlen(COMMAND->arr[0]) == 0)
        return;
    if (builtin(shell))
        return;
    fork_command(shell);
}
