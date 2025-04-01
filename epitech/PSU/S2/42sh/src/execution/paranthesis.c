/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** paranthesis.c
*/

#include "shell.h"
#include "macro.h"
#include "my.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/resource.h>

void duplicate_paranthesis(command_t *command, shell_t *shell, int fd)
{
    int original_stdout = dup(STDOUT_FILENO);
    pid_t child_pid;
    struct rusage child_rusage;

    child_pid = fork();
    if (child_pid == -1)
        return;
    if (child_pid != 0) {
        wait4(child_pid, &shell->ret, 0, &child_rusage);
    } else {
        shell->parser->command = command;
        if (fd != -2 && fd != -1) {
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        execute_all_commands(shell);
        dup2(original_stdout, STDOUT_FILENO);
        exit(shell->ret);
    }
}

static int check_for_par_redirect(command_t **command, shell_t *shell)
{
    char *filename = NULL;
    int sep = (*command)->sep;

    COMMAND = (*command);
    if (!(*command))
        return -2;
    if ((*command) && (*command)->prev)
        filename = (*command)->prev->cmd;
    if ((*command) && (sep == 2 || sep == 4)) {
        (*command) = (*command)->prev;
        return open_redirect(sep, filename);
    }
    if ((*command) && sep == 12) {
        (*command) = handle_pipe(shell, *command);
        return -3;
    }
    return -2;
}

command_t *handle_paranthesis(shell_t *shell, command_t *command)
{
    command_t *prev = command;
    int fd = -2;

    command->next = NULL;
    while (command && command->sep != 9) {
        command = command->prev;
        COMMAND = COMMAND->prev;
    }
    if (command) {
        prev = command->prev;
        command->prev = NULL;
    }
    if (prev)
        fd = check_for_par_redirect(&prev, shell);
    if (fd == -3)
        return prev;
    duplicate_paranthesis(command, shell, fd);
    if (prev)
        return prev->prev;
    return prev;
}
