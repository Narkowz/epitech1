/*
** EPITECH PROJECT, 2023
** error_handling.c
** File description:
** error_handling
*/

#include <stdlib.h>
#include "include/my_sokoban.h"

int contain_not_allowed(char *player, int i)
{
    if (player[i] != 'O' && player[i] != 'X' &&
    player[i] != 'P' && player[i] != '#' && player[i] != ' ' &&
    player[i] != '\n' && player[i] != '\0')
        return 84;
    return 0;
}

int minimal2(int count_O, int count_X, int count_P)
{
    if (count_O != count_X || count_P != 1 || count_O == 0 || count_X == 0)
        return 84;
    return 0;
}

int minimal_map(char *player)
{
    int i = 0;
    int count_O = 0;
    int count_X = 0;
    int count_P = 0;
    int state = 0;

    for (i; player[i] != '\0'; i++) {
        if (player[i] == 'O')
            count_O++;
        if (player[i] == 'X')
            count_X++;
        if (player[i] == 'P')
            count_P++;
        if (contain_not_allowed(player, i) == 84)
            return (84);
    }
    state = minimal2(count_O, count_X, count_P);
    return state;
}

int error_handling(char *player)
{
    if (minimal_map(player) == 84)
        exit(84);
}
