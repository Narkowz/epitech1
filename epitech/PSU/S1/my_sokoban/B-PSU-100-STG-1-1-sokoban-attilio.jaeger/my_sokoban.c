/*
** EPITECH PROJECT, 2023
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "include/my_sokoban.h"

int main(int ac, char **av)
{
    int state = 0;

    if (ac == 1)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h')
        display_usage();
    else
        state = initializing(ac, av);
    return state;
}
