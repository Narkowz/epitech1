/*
** EPITECH PROJECT, 2024
** command_input.c
** File description:
** command_input
*/

#include "include/minishell.h"
#include "include/my.h"

static void print_error(char *command)
{
    my_putstr(RED BOLD, 2);
    my_putstr(command, 2);
    my_putstr(": Exec format error. Wrong Architecture.\n", 2);
    my_putstr(RES, 2);
}

int command_environment(char *command, char **args, env_t *my_env, int *value)
{
    if (my_strncmp(command, "setenv", 6) == 6) {
        *value = setenvironment(args, my_env);
        return 0;
    }
    if (my_strncmp(command, "unsetenv", 8) == 8) {
        *value = unsetenvironment(args, my_env);
        return 0;
    }
    return -1;
}

char *test_all_env(char *command, char **args, env_t *my_env)
{
    int i = 0;
    char **path = NULL;
    char *test = NULL;
    struct stat sa;

    for (; my_env->tab[i] != NULL; i++)
        if (my_strncmp(my_env->tab[i], "PATH", 4) == 4)
            break;
    if (i == count_line(my_env->tab))
        return NULL;
    path = path_to_array(my_env->tab[i], path);
    for (i = 0; path[i] != NULL; i++) {
        add_word_to_string(path[i], command, &test, "/");
        if (stat(test, &sa) == 0)
            return test;
    }
    return NULL;
}

int lunch_process(char *command, char **args, env_t *my_env, int *value)
{
    pid_t p = fork();
    int result;
    struct stat sa;

    if (p == 0) {
        if (stat(command, &sa) == 0 && !S_ISDIR(sa.st_mode) &&
            ((sa.st_mode & S_IXUSR) || (sa.st_mode & S_IXGRP) ||
            (sa.st_mode & S_IXOTH)))
            execve(command, args, my_env->tab);
        else {
            mini_printf(RED BOLD "%s: Permission denied.\n", command, RES);
            exit(1);
        }
        print_error(command);
        exit(1);
    } else {
        waitpid(p, &result, 0);
        handle_segfault(result, value);
    }
}

int test_command(char *command, char **args, env_t *my_env, int *value)
{
    struct stat sa;
    char *path = NULL;

    if (basic_tests(command, args, my_env, value) == 0)
        return 0;
    if (stat(command, &sa) == 0) {
        lunch_process(command, args, my_env, value);
        return 0;
    } else {
        path = test_all_env(command, args, my_env);
        if (path != NULL) {
            lunch_process(path, args, my_env, value);
            return 0;
        }
    }
    if (command_environment(command, args, my_env, value) == 0)
        return 0;
    return -1;
}

static void free_args(char *command, char **args)
{
    if (args != NULL) {
        for (int i = 0; i <= count_args(command) + 1; i++)
            free(args[i]);
        free(args);
    }
}

char *command_input(env_t *my_env, char *command, int *value)
{
    char **args = NULL;
    size_t size = 0;
    ssize_t read = 0;

    read = getline(&command, &size, stdin);
    if (read == -1) {
        command = my_strcpy(command, "exit");
        return command;
    }
    if (my_strlen(command) == 1 && command[0] == '\n')
        return ("\0");
    command[read - 1] = '\0';
    add_args(&args, command);
    command = strtok(command, " \t\n");
    if (test_command(command, args, my_env, value) != 0) {
        mini_printf(RED BOLD "%s: Command not found.\n", command, RES);
        *value = 1;
    }
    free_args(command, args);
    return command;
}
