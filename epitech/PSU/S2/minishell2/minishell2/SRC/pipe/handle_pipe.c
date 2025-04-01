/*
** EPITECH PROJECT, 2024
** handle_pipe.c
** File description:
** handle_pipe
*/

#include "../../include/minishell.h"
#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void doing_pipe(char ***cmds, int cmd_count, int **pipes, int i)
{
    struct stat sa;

    if (i > 0) {
        dprintf(2, "sup 0\n");
        dup2(pipes[i - 1][0], STDIN_FILENO);
    }
    if (i < cmd_count - 1) {
        dprintf(2, "inf 0\n");
        dup2(pipes[i][1], STDOUT_FILENO);
    }
    for (int j = 0; j < cmd_count - 1; j++) {
        close(pipes[j][0]);
        close(pipes[j][1]);
    }
    execve(cmds[i][0], cmds[i], (char *const *)NULL);
    perror("execve");
    exit(EXIT_FAILURE);
}

static char *change_for_env(char ***cmds, env_t *my_env, int i)
{
    struct stat sa;

    if (stat(cmds[i][0], &sa) != 0)
        return test_all_env(cmds[i][0], cmds[i], my_env);
    else
        return cmds[i][0];
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

void process_commands(char ***cmds, int cmd_count, env_t *my_env)
{
    int i;
    int **pipes = malloc((cmd_count - 1) * sizeof(int *));
    pid_t pid;

    for (i = 0; i < cmd_count - 1; i++) {
        pipes[i] = malloc(2 * sizeof(int));
        pipe(pipes[i]);
    }
    for (i = 0; i < cmd_count; i++) {
        pid = fork();
        if (pid == 0) {
            cmds[i][0] = change_for_env(cmds, my_env, i);
            doing_pipe(cmds, cmd_count, pipes, i);
        }
    }
    end_pipe(pipes, cmd_count, i);
}

static int count_commands(list_t *multi)
{
    int i = 0;

    while (multi != NULL && multi->ispipe != 0) {
        i++;
        multi = multi->next;
    }
    return i + 1;
}

static void print_error(void)
{
    my_putstr(RED, 2);
    my_putstr(BOLD, 2);
    my_putstr("Invalid null command.\n", 2);
    my_putstr(RES, 2);
    exit(1);
}

char ***parse_commands(list_t *multi, char **args, int *iterate, int *nb_cmd)
{
    int nb_cmds = count_commands(multi);
    char ***cmds = malloc(sizeof(char **) * (nb_cmds + 1));

    while (multi != NULL) {
        if (multi->ispipe == 0)
            break;
        add_args(&args, multi->command);
        cmds[*iterate] = args;
        (*iterate)++;
        multi = multi->next;
    }
    if (multi != NULL) {
        add_args(&args, multi->command);
        cmds[*iterate] = args;
        (*iterate)++;
    } else
        print_error();
    cmds[*iterate] = NULL;
    *nb_cmd = nb_cmds;
    return cmds;
}

int handle_pipe(list_t *multi, char **args, env_t *my_env, int *iterate)
{
    int nb_cmds;
    char ***cmds = NULL;

    if (!multi || multi->ispipe != 1)
        return 0;
    cmds = parse_commands(multi, args, iterate, &nb_cmds);
    process_commands(cmds, nb_cmds, my_env);
    return 1;
}
