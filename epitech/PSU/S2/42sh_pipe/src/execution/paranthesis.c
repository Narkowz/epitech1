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
    pid_t child_pid;
    struct rusage child_rusage;

    child_pid = fork();
    if (child_pid == -1)
        return;
    if (child_pid != 0) {
        wait4(child_pid, &shell->ret, 0, &child_rusage);
        printf("after wait4 %d\n", shell->ret);
    } else {
        shell->parser->command = command;
        if (fd != -2 && fd != -1) {
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        execute_all_commands(shell);
        dup2(get_original_stdout(), STDOUT_FILENO);
        printf("End par %d\n", shell->ret);
        exit(shell->ret);
    }
}

static int check_for_par_redirect(command_t **command)
{
    command_t *save = *command;
    char *filename = save->cmd;

    if ((!filename || my_strlen(filename) == 0) && (*command)->prev) {
        filename = save->prev->cmd;
        *command = save->prev;
    }
    if (save && (save->sep == 2 || save->sep == 4))
        return open_redirect(save->sep, filename);
    return -2;
}

command_t *handle_paranthesis(shell_t *shell, command_t *command)
{
    command_t *prev = command;
    int fd = -2;

    command->next = NULL;
    while (command && command->sep != 9)
        command = command->prev;
    if (command) {
        prev = command->prev;
        command->prev = NULL;
    }
    if (prev)
        fd = check_for_par_redirect(&prev);
    duplicate_paranthesis(command, shell, fd);
    if (prev)
        return prev->prev;
    return prev;
}
