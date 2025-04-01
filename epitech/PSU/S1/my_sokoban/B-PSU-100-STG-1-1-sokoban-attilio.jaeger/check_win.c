/*
** EPITECH PROJECT, 2023
** check_win.c
** File description:
** check_win
*/

#include <ncurses.h>
#include "include/my_sokoban.h"

int check_win(char *player, char *copy)
{
    int i = 0;
    int count = 0;
    int count_O = 0;

    for (i; copy[i] != '\0'; i++) {
        if (copy[i] == 'O')
            count_O++;
        if (copy[i] == 'O' && player[i] == 'X')
            count++;
    }
    if (count == count_O) {
        refresh();
        return 0;
    }
    if (check_loose(player) == 1)
        return 1;
    refresh();
    return 5;
}
