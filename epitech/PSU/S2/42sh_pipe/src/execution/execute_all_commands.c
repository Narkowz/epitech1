/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** execute_all_commands.c
*/

#include "shell.h"
#include "macro.h"

void execute_all_commands(shell_t *shell)
{
    parser_t *cpy = NULL;

    if (shell)
        cpy = shell->parser;
    else
        return;
    while (cpy->command && cpy->command->next)
        cpy->command = cpy->command->next;
    while (cpy->command) {
        if (cpy->command->next && cpy->command->next->sep == 8)
            cpy->command = handle_paranthesis(shell, cpy->command);
        if (cpy->command && IS_QUOTE)
            cpy->command = handle_quote(shell, cpy->command, 0);
        if (cpy->command && IS_DIR)
            cpy->command = handle_redirect(shell, cpy->command);
        if (cpy->command && IS_PIPE)
            cpy->command = handle_pipe(shell, cpy->command);
        if (cpy->command && cpy->command->cmd)
            execute_one_command(shell, &cpy);
        if (cpy->command)
            cpy->command = cpy->command->prev;
    }
}
