/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** paranthesis.c
*/

#include "shell.h"
#include "my.h"

command_t *update_cpy(command_t *command)
{
    command_t *cpy = command;

    if (!cpy)
        return command;
    do {
        cpy = cpy->prev;
    } while (cpy && cpy->next && cpy->next->sep != 7);
    return cpy;
}

command_t *quote_gestion(shell_t *shell, command_t *command, char **input)
{
    char *quote = my_alloc_str(2048);
    command_t *cpy = update_cpy(command->prev);
    int index = 0;

    while (*(*input) && *(*input) != '\"' && *(*input) != '\'')
        *(*input)++;
    *(*input)++;
    while (*(*input) && (*(*input) != '\"' && *(*input) != '\'')) {
        quote[index] = *(*input);
        index++;
        *(*input)++;
    }
    *(*input)++;
    command->arr = my_tab_add(command->arr, quote);
    command->prev = cpy;
    return command;
}

command_t *handle_quote(shell_t *shell, command_t *command, int reset)
{
    static char *input = NULL;

    if (reset) {
        input = NULL;
        return NULL;
    }
    if (!input)
        input = my_strdup(shell->save->prec->input);
    return quote_gestion(shell, command, &input);
}
