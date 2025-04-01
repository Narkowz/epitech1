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

    while (cpy != NULL && cpy->sep == 12) {
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
    if (COMMAND->sep == 4 || COMMAND->sep == 2)
        handle_redirect(shell, COMMAND);
    if (COMMAND->next && COMMAND->next->sep == 9)
        execute_all_commands(shell);
    if (COMMAND->sep == 8)
        handle_paranthesis(shell, COMMAND);
    execute_one_command(shell);
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

static int **pipe_everything(int **pipes, int count_cmds)
{
    for (int i = 0; i < count_cmds - 1; i++) {
        pipes[i] = malloc(2 * sizeof(int));
        pipe(pipes[i]);
    }
    return pipes;
}

command_t *handle_pipe(shell_t *shell, command_t *cmd)
{
    int count_cmds = counter_cmds(cmd);
    int **pipes = malloc((LUI)(count_cmds - 1) * sizeof(int *));
    pid_t pid;
    int i = 0;

    pipes = pipe_everything(pipes, count_cmds);
    for (i = 0; i < count_cmds; i++) {
        pid = fork();
        if (pid == 0)
            doing_pipe(i, pipes, count_cmds, shell);
        COMMAND = COMMAND->prev;
        cmd = cmd->prev;
    }
    if (cmd && cmd->next) {
        if (cmd->next->sep == 4 || cmd->next->sep == 2)
            cmd = cmd->prev;
    }
    end_pipe(pipes, count_cmds, i);
    return cmd;
}
