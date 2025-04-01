/*
** EPITECH PROJECT, 2024
** add_to_environment.c
** File description:
** add_to_environment
*/

#include "include/minishell.h"
#include "include/my.h"

int count_line(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++);
    return i;
}

void rm_to_environment(char *name, env_t *my_env)
{
    int i = 0;
    int len = my_strlen(name);
    int lines = count_line(my_env->tab);
    char **new_env = malloc(lines * sizeof(char *));

    for (; my_env->tab[i] != NULL; i++)
        if (my_strncmp(my_env->tab[i], name, len, 0) == len)
            break;
    if (!my_env->tab[i + 1]) {
        free(my_env->tab[i]);
        my_env->tab[i] = NULL;
    } else {
        for (int k = 0; k < i; k++)
            new_env[k] = my_strdup(my_env->tab[k]);
        for (int k = i + 1; k < lines; k++)
            new_env[k - 1] = my_strdup(my_env->tab[k]);
        my_env->tab = new_env;
    }
}

void add_to_environment(char *name, char *value, env_t *my_env)
{
    int lines = count_line(my_env->tab);
    char **new_env = malloc((lines + 2) * sizeof(char *));

    for (int i = 0; i < lines; i++)
        new_env[i] = my_strdup(my_env->tab[i]);
    if (value == NULL)
        add_word(name, "", &name);
    else
        add_word(name, value, &name);
    new_env[lines] = my_strdup(name);
    new_env[lines + 1] = NULL;
    my_env->tab = new_env;
}
