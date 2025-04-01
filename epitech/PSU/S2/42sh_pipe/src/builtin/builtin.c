/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** builtin
*/

#include <stdbool.h>
#include "builtin.h"
#include "shell.h"
#include "macro.h"
#include "my.h"

int builtin_bis(shell_t *shell)
{
    if (strcmp(COMMAND->arr[0], "history") == 0) {
        my_history(shell);
        return true;
    }
    if (strcmp(COMMAND->arr[0], "echo") == 0) {
        my_echo(shell);
        return true;
    }
    if (strcmp(COMMAND->arr[0], "alias") == 0) {
        my_alias(shell);
        return true;
    }
    return false;
}

int builtin(shell_t *shell)
{
    if (strcmp(COMMAND->arr[0], "cd") == 0) {
        my_cd(shell);
        return true;
    }
    if (strcmp(COMMAND->arr[0], "env") == 0) {
        my_env(shell);
        return true;
    }
    if (strcmp(COMMAND->arr[0], "setenv") == 0) {
        my_setenv(shell);
        return true;
    }
    if (strcmp(COMMAND->arr[0], "unsetenv") == 0) {
        my_unsetenv(shell, 1);
        return true;
    }
    return builtin_bis(shell);
}
