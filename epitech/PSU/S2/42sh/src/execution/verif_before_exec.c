/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** verif_before_exec.c
*/

#include "my.h"
#include "main.h"
#include "macro.h"
#include "shell.h"

static int check_actual(command_t *actual, int *count_par, int *count_quote,
    int *single)
{
    if (actual->sep == 8) {
        *count_par = *count_par + 1;
        return 0;
    }
    if (actual->sep == 9) {
        *count_par = *count_par - 1;
        if (*count_par < 0) {
            my_putstr("Too many )'s.\n", 2);
            return 84;
        }
    }
    if (actual->sep == 10 && *count_quote % 2 == 0)
        *single = *single + 1;
    if (actual->sep == 7 && *single % 2 == 0)
        *count_quote = *count_quote + 1;
    return 0;
}

int redirection_verif(int last_sep, command_t *cpy)
{
    if (LAST_RREDIR && (cpy->sep == 4 || cpy->sep == 2))
        return my_putstr_return("Ambiguous output redirect.\n", 2, 84);
    if ((LAST_RREDIR) && EXIST_ERROR)
        return my_putstr_return("Missing name for redirect.\n", 2, 84);
    if (LAST_LREDIR && EXIST_ERROR)
        return my_putstr_return("Missing name for redirect.\n", 2, 84);
    if (LAST_RREDIR && cpy->sep == 12)
        return my_putstr_return("Ambiguous output redirect.\n", 2, 84);
    if ((cpy->sep == 5 || cpy->sep == 3) && EXIST_ERROR)
        return my_putstr_return("Ambiguous input redirect.\n", 2, 84);
    if (last_sep == 12 && (cpy->sep == 5 || cpy->sep == 3))
        return my_putstr_return("Ambiguous input redirect.\n", 2, 84);
    return 0;
}

static command_t *init_command_cpy(shell_t *shell)
{
    command_t *cpy = shell->parser->command;

    while (cpy && cpy->next)
        cpy = cpy->next;
    return cpy;
}

int verif_separators(shell_t *shell)
{
    command_t *cpy = init_command_cpy(shell);
    int last_sep = -1;

    while (cpy) {
        if (redirection_verif(last_sep, cpy) == 84)
            return 84;
        if (last_sep == 6 && EXIST_ERROR && DOUBLE_SEP)
            return my_putstr_return("Invalid command\n", 2, 84);
        if ((last_sep == 12 && NOT_EXIST) ||
            (last_sep == -1 && cpy->sep == 12 && EXIST_ERROR))
            return my_putstr_return("Invalid null command.\n", 2, 84);
        if (last_sep == 9 && EXIST_NEMPTY)
            return my_putstr_return("Badly placed ()'s.\n", 2, 84);
        if (cpy->sep == 8 && EXIST_NEMPTY)
            return my_putstr_return("Badly placed ()'s.\n", 2, 84);
        last_sep = cpy->sep;
        cpy = cpy->prev;
    }
    return 0;
}

int verif_before_exec(shell_t *shell)
{
    parser_t cpy = *shell->parser;
    int count_par = 0;
    int count_quote = 0;
    int single = 0;

    while (cpy.command && cpy.command->next)
        cpy.command = cpy.command->next;
    while (cpy.command) {
        if (check_actual(cpy.command, &count_par, &count_quote, &single) == 84)
            return 84;
        cpy.command = cpy.command->prev;
    }
    if (count_par != 0)
        return my_putstr_return("Too many ('s.\n", 2, 84);
    if (count_quote % 2 != 0)
        return my_putstr_return("Unmatched '\"'.\n", 2, 84);
    if (single % 2 != 0)
        return my_putstr_return("Unmatched '''.\n", 2, 84);
    return verif_separators(shell);
}
