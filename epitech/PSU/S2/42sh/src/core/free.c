/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "shell.h"
#include "usage.h"

static void free_if_use(void *ptr)
{
    if (ptr)
        free(ptr);
}

static void free_command(shell_t *shell)
{
    command_t *cpy = shell->parser->command;
    command_t *next = NULL;

    while (cpy) {
        next = cpy->next;
        for (int i = 0; cpy->arr != NULL && cpy->arr[i]; i++)
            free_if_use(cpy->arr[i]);
        free_if_use(cpy->cmd);
        free_if_use(cpy->arr);
        free_if_use(cpy);
        cpy = next;
    }
    free_if_use(cpy);
}

void free_shell_contain(shell_t *shell)
{
    reset_std();
    if (!shell)
        return;
    handle_quote(NULL, NULL, 1);
    free(shell->save->input);
    shell->save->input = NULL;
    if (shell && shell->parser && shell->parser->command)
        free_command(shell);
}

void free_alias(shell_t *shell)
{
    alias_t *next = NULL;

    while (shell->alias) {
        next = shell->alias->next;
        free_if_use(shell->alias->initial);
        free_if_use(shell->alias->result);
        free_if_use(shell->alias);
        shell->alias = next;
    }
}

void free_save(shell_t *shell)
{
    save_t *temp = shell->save;

    while (shell->save) {
        temp = shell->save->prec;
        free_if_use(shell->save->raw_input);
        free_if_use(shell->save->input);
        free_if_use(shell->save->time);
        free_if_use(shell->save);
        shell->save = temp;
    }
}

void free_shell(shell_t *shell)
{
    free_shell_contain(shell);
    free_alias(shell);
    free_save(shell);
    if (!shell->parser)
        return;
    if (shell && shell->parser && shell->parser->input)
        free_if_use(shell->parser->input);
    for (int i = 0; i < 14; i++) {
        if (shell->parser && shell->parser->separators &&
            shell->parser->separators[i])
            free_if_use(shell->parser->separators[i]);
    }
    if (shell->parser->separators)
        free_if_use(shell->parser->separators);
    free_if_use(shell->parser);
    free_if_use(shell);
}
