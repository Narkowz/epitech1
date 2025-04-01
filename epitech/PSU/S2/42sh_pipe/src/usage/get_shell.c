/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** get_shell
*/

#include "shell.h"
#include "my.h"

/**
 * @brief Initialize a sheel at first call then give us the same shell back
 * @return The address of the shell_t structure
 */
shell_t *get_shell(void)
{
    static shell_t *shell = NULL;

    if (!shell)
        shell = malloc((size_t)sizeof(shell_t));
    return shell;
}
