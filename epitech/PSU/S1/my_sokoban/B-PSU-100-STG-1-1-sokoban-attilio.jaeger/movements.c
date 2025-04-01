/*
** EPITECH PROJECT, 2023
** movements.c
** File description:
** movements
*/

#include <ncurses.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my_sokoban.h"

int find_player(const char *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i++)
        if (str[i] == 'P')
            return i;
    return -1;
}

static void without_border_1d(char *player, int i, int key)
{
    if (key == 100) {
        if (player[i + 1] == '\n')
            player[i] = 'P';
        else
            player[i + 1] = 'P';
    }
    if (key == 113) {
        if (player[i - 1] == '\n')
            player[i] = 'P';
        else
            player[i - 1] = 'P';
    }
}

static void without_border_2d(char *player, int i, int key)
{
    int len = line_len(player, i);
    int len_up = line_len_up(player, i);
    int full_len = my_strlen(player);

    if (key == 122) {
        if (player[i - len_up] < 0 && player[i - len_up] != ' ' &&
        player[i - len_up] != 'O')
            player[i] = 'P';
        else
            player[i - len_up] = 'P';
    }
    if (key == 115) {
        if (player[i + len + 1] > full_len && player[i + len + 1] != ' ' &&
        player[i + len + 1] != 'O')
            player[i] = 'P';
        else
            player[i + len + 1] = 'P';
    }
}

char *right(char *player, char *copy)
{
    int i = find_player(player);
    int key = 100;

    move(0, 0);
    clrtoeol();
    player = test_assets(player, copy);
    if (player[i + 1] == 'X' && player[i + 2] != '#' &&
    player[i + 2] != 'X') {
        player[i + 2] = player[i + 1];
        player[i + 1] = 'P';
    } else if (player[i + 1] == 'X' && (player[i + 2] == '#' ||
    player[i + 2] == 'X'))
        player[i] = 'P';
    else
        without_border_1d(player, i, key);
    mvprintw(0, 0, player);
    return player;
}

char *left(char *player, char *copy)
{
    int i = find_player(player);
    int key = 113;

    move(0, 0);
    clrtoeol();
    player = test_assets(player, copy);
    if (player[i - 1] == 'X' && player[i - 2] != '#' &&
    player[i - 2] != 'X') {
        player[i - 2] = player[i - 1];
        player[i - 1] = 'P';
    } else if (player[i - 1] == 'X' && (player[i - 2] == '#' ||
    player[i - 2] == 'X'))
        player[i] = 'P';
    else
        without_border_1d(player, i, key);
    mvprintw(0, 0, player);
    return player;
}

char *upward(char *player, char *copy)
{
    int i = find_player(player);
    int len = line_len_up(player, i);
    int len_line_next = line_len_up(player, i - len - 1);
    int key = 122;

    move(0, 0);
    clrtoeol();
    player = test_assets(player, copy);
    if (player[i - len] == 'X' && player[i - len - len_line_next] != '#' &&
    player[i - len - len_line_next] != 'X') {
        player[i - len - len_line_next] = player[i - len];
        player[i - len] = 'P';
    } else if (player[i - len] == 'X' &&
    (player[i - len - len_line_next] == '#' ||
    player[i - len - len_line_next] == 'X')) {
        player[i] = 'P';
    } else
        without_border_2d(player, i, key);
    mvprintw(0, 0, player);
    return player;
}

char *downward(char *player, char *copy)
{
    int i = find_player(player);
    int len = line_len(player, i);
    int len_next_line = line_len(player, i  + len + 1);
    int key = 115;

    clrtoeol();
    player = test_assets(player, copy);
    if (player[i + len + 1] == 'X' &&
    player[i + len + len_next_line + 2] != '#' &&
    player[i + len + len_next_line + 2] != 'X') {
        player[i + len + len_next_line + 2] = player[i + len + 1];
        player[i + len + 1] = 'P';
    } else if (player[i + len + 1] == 'X' &&
    (player[i + len + len_next_line + 2] == '#' ||
    player[i + len + len_next_line + 2] == 'X'))
        player[i] = 'P';
    else
        without_border_2d(player, i, key);
    mvprintw(0, 0, player);
    return player;
}
