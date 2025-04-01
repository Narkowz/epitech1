/*
** EPITECH PROJECT, 2024
** shell.c
** File description:
** shell
*/

#include "include/minishell.h"
#include "include/my.h"

void print_prompt(void)
{
    mini_printf(RED BOLD "mario » " RES);
}

int shell(env_t *my_env, list_t *multi)
{
    char *command = NULL;
    int value = 0;

    do {
        if (isatty(0))
            print_prompt();
        command = command_input(my_env, command, &value, multi);
    } while (my_strcmp("exit", command) != 0);
    free(command);
    return value;
}
