/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "shell.h"

static void free_command(shell_t *shell)
{
    command_t *cpy = shell->parser->command;
    command_t *next = NULL;

    while (cpy) {
        next = cpy->next;
        for (int i = 0; cpy->arr != NULL && cpy->arr[i]; i++)
            free(cpy->arr[i]);
        free(cpy->cmd);
        free(cpy->arr);
        free(cpy);
        cpy = next;
    }
    free(cpy);
}

void free_shell_contain(shell_t *shell)
{
    if (!shell)
        return;
    handle_quote(NULL, NULL, 1);
    free(shell->save->input);
    shell->save->input = NULL;
    if (shell && shell->parser && shell->parser->command)
        free_command(shell);
}

void free_shell(shell_t *shell)
{
    if (!shell->parser) {
        free(shell);
        return;
    }
    free_shell_contain(shell);
    if (shell && shell->parser && shell->parser->input)
        free(shell->parser->input);
    for (int i = 0; i < 12; i++) {
        if (shell->parser && shell->parser->separators &&
            shell->parser->separators[i])
            free(shell->parser->separators[i]);
    }
    if (shell->parser->separators)
        free(shell->parser->separators);
    free(shell->parser);
    free(shell);
}
