/*
** EPITECH PROJECT, 2024
** crocus
** File description:
** handle_error.c
*/

#include "crocus.h"

static int is_a_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (my_isnum(str[i]) != 0)
            return 84;
    return 0;
}

static int is_an_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (my_isalpha(str[i]) != 0)
            return 84;
    return 0;
}

static int check_number(char **av)
{
    if (strcmp(av[1], "-n") == 0)
        if (is_a_number(av[2]) == 0)
            return 0;
    if (strcmp(av[1], "-n") != 0 && strcmp(av[3], "-n") == 0)
        if (is_a_number(av[4]) == 0)
            return 0;
    return 84;
}

static int check_alpha(char **av)
{
    if (strcmp(av[1], "-s") == 0)
        if (is_an_alpha(av[2]) == 0)
            return 0;
    if (strcmp(av[1], "-s") != 0 && strcmp(av[3], "-s") == 0)
        if (is_an_alpha(av[4]) == 0)
            return 0;
    return 84;
}

static int check_args(char **av)
{
    if (check_number(av) != 0)
        return 84;
    if (check_alpha(av) != 0)
        return 84;
    return 0;
}

int handle_error(int ac, char **av)
{
    if (ac == 3 && strcmp(av[1], "-n") == 0)
        if (is_a_number(av[2]) == 0)
            return 0;
    if (ac == 5)
        return check_args(av);
    return 84;
}
