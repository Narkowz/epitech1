/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** setenv
*/

#include <stdbool.h>
#include "my.h"
#include "shell.h"
#include "macro.h"

static int is_wrong_variable(char *variable)
{
    if ((variable[0] < 'A' || (variable[0] > 'Z'
        && variable[0] < 'a') || variable[0] > 'z') && variable[0] != '_') {
        my_putstr("setenv: Variable name must begin with a letter.\n", 2);
        return true;
    }
    for (int i = 1; variable[i] != '\0'; i++) {
        if ((variable[i] < '0' || (variable[i] > '9' && variable[i] < 'A') ||
            (variable[i] > 'Z' && variable[i] < 'a') || variable[i] > 'z') &&
            variable[i] != '_' && variable[i] != '.') {
            my_putstr("setenv: Variable name must contain", 2);
            my_putstr(" alphanumeric characters.\n", 2);
            return true;
        }
    }
    return false;
}

static void setenv_variable(shell_t *shell)
{
    size_t len = strlen(COMMAND->arr[1]);

    if (is_wrong_variable(COMMAND->arr[1])) {
        shell->ret = 1;
        return;
    }
    for (int i = 0; shell->env[i]; i++) {
        if (strlen(shell->env[i]) > len &&
        !strncmp(shell->env[i], COMMAND->arr[1], len)) {
            shell->env[i] = strdup(my_strcat(COMMAND->arr[1], "="));
        }
    }
    append(&shell->env, my_strcalloc(COMMAND->arr[1], "="));
}

static void setenv_value(shell_t *shell)
{
    size_t len = strlen(COMMAND->arr[1]);

    if (is_wrong_variable(COMMAND->arr[1])) {
        shell->ret = 1;
        return;
    }
    for (int i = 0; shell->env[i]; i++) {
        if (strlen(shell->env[i]) > len &&
        !strncmp(shell->env[i], COMMAND->arr[1], len)) {
            shell->env[i] = my_strcalloc
            (my_strcalloc(COMMAND->arr[1], "="), COMMAND->arr[2]);
        }
    }
    append(&shell->env, my_strcalloc
    (my_strcalloc(COMMAND->arr[1], "="), COMMAND->arr[2]));
}

void my_setenv(shell_t *shell)
{
    switch (my_tab_len(COMMAND->arr)) {
        case 1:
            my_print_tab(shell->env, 1);
            break;
        case 2:
            setenv_variable(shell);
            break;
        case 3:
            setenv_value(shell);
            break;
        default:
            my_putstr("setenv: Too many arguments.\n", 2);
    }
}
