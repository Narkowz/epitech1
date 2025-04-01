/*
** EPITECH PROJECT, 2024
** my_pipe.c
** File description:
** my_pipe
*/

#include "my.h"

int main(int ac, char **av)
{
    int pipefd[2];
    pid_t ls_pid;
    pid_t grep_pid;
    char **args1 = my_str_to_word_array(av[1], args1);
    char **args2 = my_str_to_word_array(av[2], args2);

    pipe(pipefd);
    ls_pid = fork();
    if (ls_pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execve(args1[0], args1, (char **)NULL);
    }
    grep_pid = fork();
    if (grep_pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        execve(args2[0], args2, (char **)NULL);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(ls_pid, NULL, 0);
    waitpid(grep_pid, NULL, 0);
    return 0;
}
