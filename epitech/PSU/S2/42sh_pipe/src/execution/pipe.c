/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** pipe
*/

#include "shell.h"
#include "macro.h"

int counter_cmds(command_t *cmd)
{
    command_t *cpy = cmd;
    int count = 0;

    while (cpy != NULL && cpy->sep == 1) {
        cpy = cpy->prev;
        count++;
    }
    return count + 1;
}

void doing_pipe(int i, int **pipes, int count_cmds, shell_t *shell)
{
    if (i > 0)
        dup2(pipes[i - 1][0], STDIN_FILENO);
    if (i < count_cmds - 1)
        dup2(pipes[i][1], STDOUT_FILENO);
    for (int j = 0; j < count_cmds - 1; j++) {
        close(pipes[j][0]);
        close(pipes[j][1]);
    }
    execute_one_command(shell, NULL);
    exit(EXIT_SUCCESS);
}

static void end_pipe(int **pipes, int cmd_count, int i)
{
    for (int j = 0; j < cmd_count - 1; j++) {
        close(pipes[j][0]);
        close(pipes[j][1]);
    }
    for (i = 0; i < cmd_count; i++) {
        wait(NULL);
    }
    for (i = 0; i < cmd_count - 1; i++) {
        free(pipes[i]);
    }
    free(pipes);
}

command_t *handle_pipe(shell_t *shell, command_t *cmd)
{
    int count_cmds = counter_cmds(cmd);
    int **pipes = malloc((count_cmds - 1) * sizeof(int *));
    int i = 0;
    pid_t pid;

    for (i = 0; i < count_cmds - 1; i++) {
        pipes[i] = malloc(2 * sizeof(int));
        pipe(pipes[i]);
    }
    for (i = 0; i < count_cmds; i++) {
        pid = fork();
        if (pid == 0)
            doing_pipe(i, pipes, count_cmds, shell);
        COMMAND = COMMAND->prev;
        cmd = cmd->prev;
    }
    end_pipe(pipes, count_cmds, i);
    return cmd;
}
