/*
** EPITECH PROJECT, 2024
** handle_args.c
** File description:
** handle_args
*/

#include "include/minishell.h"
#include "include/my.h"

int count_args(char *command)
{
    int i = 0;
    int count = 0;

    for (; command[i] != '\0'; i++)
        if ((command[i] == ' ' || command[i] == '\t') &&
            (command[i + 1] != ' ' || command[i + 1] != '\t'))
            count++;
    return count;
}

char **handle_args(char *command, char **args)
{
    char *token = NULL;
    int i = 0;

    token = strtok(command, " \t\n");
    while (token != NULL) {
        args[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        my_strcpy(args[i], token);
        i++;
        token = strtok(NULL, " \t\n");
    }
    return args;
}

int add_args(char ***args, char *command)
{
    int nb_args = count_args(command) + 1;

    if (nb_args >= 1) {
        *args = malloc(sizeof(char *) * (nb_args + 1));
        (*args)[nb_args] = NULL;
        handle_args(command, *args);
        return 0;
    } else
        return 1;
}
