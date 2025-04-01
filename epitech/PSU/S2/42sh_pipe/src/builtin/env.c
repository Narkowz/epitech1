/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** env
*/

#include "shell.h"
#include "my.h"

void my_env(shell_t *shell)
{
    if (my_tab_len(shell->parser->command->arr) > 1) {
        my_putstr("env: '", 2);
        my_putstr(shell->parser->command->arr[1], 2);
        my_putstr("': No such file or directory\n", 2);
        return;
    }
    my_print_tab(shell->env, 1);
}
