/*
** EPITECH PROJECT, 2024
** B-PSU-S2
** File description:
** hold_parsing
*/

#include "usage.h"
#include "shell.h"
#include "main.h"
#include "builtin.h"
#include <stdlib.h>
#include <string.h>

static char **init_sep(void)
{
    char **separators = malloc(sizeof(char *) * 13);

    separators[0] = NULL;
    separators[1] = strdup("|");
    separators[2] = strdup(">>");
    separators[3] = strdup("<<");
    separators[4] = strdup(">");
    separators[5] = strdup("<");
    separators[6] = strdup(";");
    separators[7] = strdup("\"");
    separators[8] = strdup("(");
    separators[9] = strdup(")");
    separators[10] = strdup("'");
    separators[11] = NULL;
    separators[12] = NULL;
    return separators;
}

static parser_t *init_parser(shell_t *shell)
{
    parser_t *parser = malloc(sizeof(parser_t));
    char *temp = NULL;

    if (!shell->save->input)
        return NULL;
    temp = my_cleanstr(shell->save->input, " \t\n");
    if (!temp)
        return NULL;
    parser->input = strdup(temp);
    parser->separators = init_sep();
    parser->command = malloc(sizeof(command_t));
    parser->command->arr = NULL;
    parser->command->cmd = NULL;
    parser->command->prev = NULL;
    parser->command->next = NULL;
    parser->command->sep = T_OTHER;
    free(temp);
    return parser;
}

void hold_parsing(shell_t *shell)
{
    apply_alias(shell);
    shell->parser = init_parser(shell);
    if (!shell->parser)
        return;
    parse_command(shell->parser);
}
