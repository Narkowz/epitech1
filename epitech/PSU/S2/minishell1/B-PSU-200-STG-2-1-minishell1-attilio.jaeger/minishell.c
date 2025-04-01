/*
** EPITECH PROJECT, 2024
** minishell.c
** File description:
** minishell
*/

#include "include/my.h"
#include "include/minishell.h"

int main(int ac, char **av, char **env)
{
    int status;
    env_t *my_env = NULL;

    if (ac > 1)
        return 84;
    my_env = malloc(sizeof(env_t));
    my_env->tab = copy_env(env);
    status = shell(my_env);
    return status;
}
