/*
** EPITECH PROJECT, 2023
** my_sokoban.c
** File description:
** main
*/

#include <ncurses.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my_sokoban.h"

int mon_strlen(const char *str)
{
    int i = 0;

    for (i; str[i] != '\n' && str[i] != '\0'; i++);
    return i;
}

char *test_assets(char *player, char *copy)
{
    int pos_player = find_player(player);

    if (copy[pos_player] == 'O')
        player[pos_player] = 'O';
    else
        player[pos_player] = ' ';
    return player;
}

static void initialize_game(char *player)
{
    int x = 0;
    int y = 0;

    mvprintw(y, x, player);
    refresh();
}

char *in_3d(char *player, int key, char *copy)
{
    int len = line_len_up(player, find_player(player));
    int len_down = line_len(player, find_player(player)) + 1;
    int full_len = my_strlen(player);

    if (key == KEY_DOWN && player[find_player(player) + len_down] != '#') {
        if (find_player(player) + len_down < full_len) {
                player = downward(player, copy);
            }
        }
    if (key == KEY_UP && player[find_player(player) - len] != '#') {
        if (find_player(player) - len > 0) {
            player = upward(player, copy);
        }
    }
    return player;
}

int check_event(char *player, char *copy)
{
    int key = 0;
    int len = my_strlen(player);
    int state = 5;

    keypad(stdscr, TRUE);
    ESCDELAY = 5;
    while (key != 27 && state == 5) {
        key = getch();
        if (key == KEY_LEFT && player[find_player(player) - 1] != '#') {
            player = left(player, copy);
        }
        if (key == KEY_RIGHT && player[find_player(player) + 1] != '#') {
            player = right(player, copy);
        }
        if (key == 32)
            player = reset(player, copy);
        player = in_3d(player, key, copy);
        state = check_win(player, copy);
    }
    return state;
}

int initializing(int ac, char **av)
{
    char *player = opening_file(av[1]);
    char *copy_player;
    int state = 0;

    if (error_handling(player) != 0)
        return 84;
    copy_player = my_strdup(player);
    initscr();
    noecho();
    initialize_game(player);
    state = check_event(player, copy_player);
    endwin();
    return state;
}
