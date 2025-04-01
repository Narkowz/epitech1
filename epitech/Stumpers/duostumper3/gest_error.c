/*
** EPITECH PROJECT, 2024
** MixWord
** File description:
** gest_error.c
*/

#include "include/mix.h"

int gest_error(int ac, char **av)
{
    if (ac > 5 || ac < 3 || ac == 4)
        return 84;
    if (av[1][0] == '-' && av[1][1] != 'f')
        return 84;
    if (ac == 5 && my_str_is_num(av[4]) == 1)
        return 84;
    if (ac == 5 && av[3][0] == '-' && av[3][1] != 's')
        return 84;
}
