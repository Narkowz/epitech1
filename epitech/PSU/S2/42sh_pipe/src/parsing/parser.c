/*
** EPITECH PROJECT, 2024
** B-PSU-S2
** File description:
** parser
*/

#include "usage.h"
#include "shell.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>

static void add_command(command_t **list)
{
    command_t *new = malloc(sizeof(command_t));

    if (new == NULL)
        return;
    new->cmd = NULL;
    new->sep = 0;
    new->prev = NULL;
    (*list)->prev = new;
    new->next = *list;
    *list = new;
}

static int is_sep(char c)
{
    if (c == '|' || c == '<' || c == '>' || c == ';' || c == '"' || c == '(' ||
        c == ')' || c == '\0' || c == '\'')
        return 1;
    return 0;
}

static char *get_separator(parser_t *parser, char *str)
{
    if (*str == '\0') {
        parser->command->sep = T_EOF;
        return str;
    }
    for (int i = 1; i < NB_SEP; i++) {
        if (strncmp(str, parser->separators[i],
            strlen(parser->separators[i])) == 0) {
            parser->command->sep = i;
            str += strlen(parser->separators[i]) - 1;
            add_command(&parser->command);
            break;
        }
    }
    return str;
}

void parse_command(parser_t *parser)
{
    char *str = strdup(parser->input);
    command_t *tmp = NULL;

    if (!str)
        parser->command->cmd = NULL;
    for (; str && *str != '\0'; str++) {
        if (!is_sep(*str))
            parser->command->cmd = my_strncat(parser->command->cmd, str, 1);
        if (is_sep(*str))
            str = get_separator(parser, str);
    }
    tmp = parser->command;
    for (; tmp->next; tmp = tmp->next);
    for (; tmp; tmp = tmp->prev) {
        tmp->cmd = my_cleanstr(tmp->cmd, " \t\n");
        tmp->arr = simple_str_to_array(tmp->cmd, ' ');
    }
}
