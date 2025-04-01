/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** init
*/

#include "shell.h"
#include "builtin.h"
#include <stdlib.h>

/**
 * @brief Put Empty variable in each of the shell_t param
 * @param shell_t* the address of the shell
 * @return The address of the shell_t structure
 */
shell_t *init_shell(shell_t *shell, char **env)
{
    shell->parser = NULL;
    shell->save = malloc(sizeof(save_t));
    shell->save->input = NULL;
    shell->save->next = NULL;
    shell->save->prec = NULL;
    shell->alias = NULL;
    shell->env = env;
    shell->ret = 0;
    get_alias(shell);
    return shell;
}
