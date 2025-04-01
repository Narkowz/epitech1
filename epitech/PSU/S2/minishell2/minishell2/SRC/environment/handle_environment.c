/*
** EPITECH PROJECT, 2024
** print_environment.c
** File description:
** print_environment
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

char **copy_env(char **env)
{
    int lines = count_line(env);
    char **new_env = malloc(sizeof(char *) * (lines + 1));
    int i = 0;

    for (; env[i] != NULL; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[i] = NULL;
    return new_env;
}

static int test_overwrite(char **args, env_t *my_env)
{
    int i = 0;
    char *name = NULL;
    int len = 0;
    int exist = 0;

    add_word_to_string(args[1], "=", &name, NULL);
    len = my_strlen(name);
    for (; my_env->tab[i] != NULL; i++)
        if (my_strncmp(my_env->tab[i], name, len, 0) == len)
            exist = 1;
    if (exist == 1)
        return 1;
    return 0;
}

int unsetenvironment(char **args, env_t *my_env)
{
    char *name = NULL;
    int i = 0;

    if (args[1] != NULL) {
        for (; args[i] != NULL; i++) {
            name = my_strdup(args[i]);
            add_word_to_string(name, "=", &name, NULL);
            rm_to_environment(name, my_env);
        }
    } else {
        mini_printf(RED BOLD "%s: Too few arguments.\n", args[0], RES);
        return 1;
    }
}

static int test_char(char **arg)
{
    int i = 0;
    int count = 0;
    char *args = arg[1];

    for (; args[i] != '\0'; i++)
        if (args[i] < 48 || (args[i] > 57 && args[i] < 65) ||
            (args[i] > 90 && args[i] < 95) || (args[i] > 95 && args[i] < 97)
            || args[i] > 122) {
            count++;
            break;
        }
    if (count != 0) {
        mini_printf(RED BOLD
            "%s: Variable name must contain alphanumeric characters.\n",
            arg[0], RES);
        return count;
    }
    return 0;
}

static int test_environment(char **args)
{
    if (test_char(args) != 0)
        return 1;
    if (count_line(args) > 3) {
        mini_printf(RED BOLD "%s: Too many arguments.\n", args[0], RES);
        return 1;
    }
    return 0;
}

int setenvironment(char **args, env_t *my_env)
{
    char *name = NULL;
    char *value = NULL;

    if (args[1] == NULL) {
        print_env(my_env);
        return 0;
    }
    if (test_environment(args) != 0)
        return 1;
    if (test_overwrite(args, my_env) == 0) {
        name = my_strdup(args[1]);
        if (args[2])
            value = my_strdup(args[2]);
        if (name)
            add_to_environment(name, value, my_env);
    } else
        change_environment(args[1], args[2], my_env);
    return 0;
}

char *research_env(char *research, env_t *my_env)
{
    char *path = NULL;
    int i = 0;
    int len = my_strlen(research) + 1;
    int count = 0;

    add_word_to_string(research, "=", &research, NULL);
    for (; my_env->tab[i] != NULL; i++)
        if (my_strncmp(my_env->tab[i], research, len, 0) == len) {
            count++;
            break;
        }
    if (count != 1)
        return NULL;
    path = my_strdup(my_env->tab[i]);
    strtok(path, "=");
    path = strtok(NULL, "=");
    return path;
}

void print_env(env_t *my_env)
{
    for (int i = 0; my_env->tab[i] != NULL; i++)
        mini_printf("%s\n", my_env->tab[i]);
}
