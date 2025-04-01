/*
** EPITECH PROJECT, 2023
** reset.c
** File description:
** reset
*/

#include <ncurses.h>
#include "include/my_sokoban.h"

char *reset(char *player, char *copy)
{
    player = my_strdup(copy);
    mvprintw(0, 0, player);
    return player;
}
