/*
** EPITECH PROJECT, 2024
** handle_pipe.c
** File description:
** handle_pipe
*/

#include "include/minishell.h"
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int pipe_first_command(char **args1, int pipefd[2], pid_t ls_pid)
{
    ls_pid = fork();
    if (ls_pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execve(args1[0], args1, (char **)NULL);
    }
}

int pippe_second_command(char **args2, int pipefd[2], pid_t grep_pid)
{
    grep_pid = fork();
    if (grep_pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        execve(args2[0], args2, (char **)NULL);
    }
}

int process_pipe(list_t *multi, char **args, env_t *my_env)
{
    int pipefd[2] = {0};
    pid_t ls_pid;
    pid_t grep_pid;
    char **args1 = args;
    char **args2 = NULL;

    multi = multi->next;
    remove_first_space(&multi->command);
    args2 = my_str_to_word_array(multi->command, args2);
    args1[0] = test_all_env(args1[0], args1, my_env);
    args2[0] = test_all_env(args2[0], args2, my_env);
    pipe(pipefd);
    pipe_first_command(args1, pipefd, ls_pid);
    pippe_second_command(args2, pipefd, grep_pid);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(ls_pid, NULL, 0);
    waitpid(grep_pid, NULL, 0);
}

int handle_pipe(list_t *multi, char **args, env_t *my_env)
{
    if (multi->ispipe == 1) {
        process_pipe(multi, args, my_env);
        return 1;
    }
    return 0;
}
