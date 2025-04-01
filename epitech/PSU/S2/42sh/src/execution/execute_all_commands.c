/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** execute_all_commands.c
*/

#include "shell.h"
#include "macro.h"
#include "my.h"

static parser_t *init_cpy(shell_t *shell)
{
    parser_t *cpy = NULL;

    if (shell)
        cpy = shell->parser;
    else
        return NULL;
    while (cpy->command && cpy->command->next)
        cpy->command = cpy->command->next;
    return cpy;
}

static void check_operator(shell_t *shell, parser_t *cpy)
{
    if (cpy->command->next && cpy->command->next->sep == 8)
        cpy->command = handle_paranthesis(shell, cpy->command);
    if (cpy->command && IS_QUOTE)
        cpy->command = handle_quote(shell, cpy->command, 0);
    if (cpy->command && (IS_DIR || IS_INVDIR))
        cpy->command = handle_redirect(shell, cpy->command);
    if (cpy->command && IS_AND)
        cpy->command = handle_and(shell, cpy->command);
    if (cpy->command && IS_OR)
        cpy->command = handle_or(shell, cpy->command);
}

void execute_all_commands(shell_t *shell)
{
    parser_t *cpy = init_cpy(shell);

    if (handle_globing(shell, cpy) != 0)
        return;
    while (cpy && cpy->command) {
        check_operator(shell, cpy);
        if (cpy->command && IS_PIPE) {
            cpy->command = handle_pipe(shell, cpy->command);
            continue;
        }
        if (cpy->command && (cpy->command->cmd || cpy->command->arr))
            execute_one_command(shell);
        if (cpy->command) {
            cpy->command = cpy->command->prev;
        }
    }
}
