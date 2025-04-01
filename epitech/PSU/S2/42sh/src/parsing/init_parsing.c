/*
** EPITECH PROJECT, 2024
** B-PSU-S2
** File description:
** hold_parsing
*/

#include "usage.h"
#include "shell.h"
#include "main.h"
#include "my.h"
#include "builtin.h"
#include <stdlib.h>
#include <string.h>

static char **init_sep(void)
{
    char **separators = my_alloc_tab(14);

    separators[0] = NULL;
    separators[1] = strdup("||");
    separators[2] = strdup(">>");
    separators[3] = strdup("<<");
    separators[4] = strdup(">");
    separators[5] = strdup("<");
    separators[6] = strdup(";");
    separators[7] = strdup("\"");
    separators[8] = strdup("(");
    separators[9] = strdup(")");
    separators[10] = strdup("'");
    separators[11] = strdup("&&");
    separators[12] = strdup("|");
    separators[13] = NULL;
    separators[14] = NULL;
    return separators;
}

static parser_t *init_parser(shell_t *shell)
{
    parser_t *parser = malloc(sizeof(parser_t));
    char *temp = NULL;
    char *empty_char = my_strdup(" \t\n");

    if (!shell->save->prec->input)
        return NULL;
    temp = my_cleanstr(shell->save->prec->input, empty_char);
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
    free(empty_char);
    return parser;
}

int hold_parsing(shell_t *shell)
{
    if (apply_alias(shell) == 1) {
        printf("Alias loop.\n");
        fflush(stdout);
        return 84;
    }
    shell->parser = init_parser(shell);
    if (!shell->parser)
        return 0;
    parse_command(shell->parser);
    return 0;
}
