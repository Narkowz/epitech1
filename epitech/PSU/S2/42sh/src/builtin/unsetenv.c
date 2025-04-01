/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** unsetenv
*/

#include "my.h"
#include "shell.h"

static void unset(char ***env, int index)
{
    for (int i = index; (*env)[i]; i++)
        (*env)[i] = (*env)[i + 1];
}

void my_unsetenv(shell_t *shell, int index)
{
    size_t len;

    if (my_tab_len(shell->parser->command->arr) == 1) {
        my_putstr("unsetenv: Too few arguments.\n", 2);
        return;
    }
    len = strlen(shell->parser->command->arr[index]);
    for (int i = 0; shell->env[i]; i++)
        if (strlen(shell->env[i]) >= len &&
        !strncmp(shell->env[i], shell->parser->command->arr[index], len))
            unset(&shell->env, i);
    if (shell->parser->command->arr[index + 1])
        my_unsetenv(shell, index + 1);
}
