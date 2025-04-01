/*
** EPITECH PROJECT, 2024
** step4.c
** File description:
** step4
*/

#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

int execution(char *name, char *command, int nb_args)
{
    char *args = NULL;
    char **test = NULL;
    int len = 0;

    printf("Child PID: %d\n", getpid());
    if (nb_args >= 1) {
        test = malloc(sizeof(char *) * nb_args);
        args = strtok(command, " ");
        args = strtok(NULL, " ");
        for (int i = 0; args != NULL; i++) {
            len = my_strlen(args);
            test[i] = malloc(sizeof(char) * len + 1);
            test[i] = strdup(args);
            args = strtok(NULL, " ");
        }
        return execve(command, test, NULL);
    } else
        return execve(command, NULL, NULL);
}

int main(int ac, char **av, char **env)
{
    char *strtoken;
    int i = 0;
    char *name;
    char *command = strdup(av[1]);
    int status = 3;
    pid_t p;

    name = strtok(av[1], " ");
    printf("Program name: %s\n", name);
    for (; strtoken != NULL; i++)
        strtoken = strtok(NULL, " ");
    printf("Nb args: %d\n", i - 1);
    printf("PID: %d\n", getpid());
    p = fork();
    if (p == 0)
        status = execution(name, command, i - 1);
    else
        waitpid(p, &status, 0);
    printf("Program terminated.\n");
    printf("%d\n", status);
    if (status != -1)
        printf("Status: OK\n");
    else
        printf("Status: Segmentation fault\n");
    return 0;
}
