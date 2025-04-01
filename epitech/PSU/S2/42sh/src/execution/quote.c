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
    } while (cpy && cpy->next && cpy->next->sep != 7 && cpy->next->sep != 10);
    return cpy;
}

static command_t *update_command(command_t *command, command_t *cpy,
    char *quote, command_t *src)
{
    src->arr = my_tab_add(src->arr, quote);
    src->prev = cpy;
    return src;
}

char change_type(char input)
{
    if (input == '\'')
        return '\'';
    else
        return '\"';
}

command_t *quote_gestion(shell_t *shell, command_t *command, char **input,
    command_t *src)
{
    char *quote = my_alloc_str(2048);
    command_t *cpy = update_cpy(command->prev);
    int index = 0;
    char type = '\'';

    while (*(*input) && *(*input) != '\"' && *(*input) != '\'')
        *(*input)++;
    if (!*(*input))
        return command;
    type = change_type(*(*input));
    *(*input)++;
    while (*(*input) && *(*input) != type) {
        quote[index] = *(*input);
        index++;
        *(*input)++;
    }
    *(*input)++;
    return update_command(command, cpy, quote, src);
}

command_t *handle_quote(shell_t *shell, command_t *command, int reset)
{
    static char *input = NULL;
    command_t *src = command;

    if (reset) {
        input = NULL;
        return NULL;
    }
    if (!input)
        input = my_strdup(shell->save->prec->raw_input);
    while (command && (command->sep == 7 ||
        command->sep == 10)) {
        quote_gestion(shell, command, &input, src);
        command = command->prev;
    }
    if (src && src->prev && src->prev->cmd && my_strlen(src->prev->cmd) != 0) {
        src->arr = my_tab_add(src->arr, src->prev->cmd);
        src->prev = src->prev->prev;
    }
    return src;
}
