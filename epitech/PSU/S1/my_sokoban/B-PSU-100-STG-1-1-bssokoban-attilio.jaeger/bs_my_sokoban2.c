/*
** EPITECH PROJECT, 2023
** bs_my_sokoban2.c
** File description:
** bs_my_sokoban2
*/

#include <ncurses.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int find_o(const char *str)
{
    int i;

    for (i = 0; i < strlen(str); i++)
        if (str[i] == 'P')
            return i;
    return -1;
}

char *swap(const char *player, int key)
{
    int i = find_o(player);
    char *new_player = strdup(player);

    if (i != -1) {
        if (key == 100) {
            new_player[i] = '.';
            new_player[i + 1] = 'P';
        } else {
            new_player[i] = '.';
            new_player[i - 1] = 'P';
        }
    }
    return new_player;
}

void initialize_game(char *str, char *player)
{
    int x = 0;
    int y = 0;

    mvprintw(y, x, str);
    mvprintw(y, x, player);
    refresh();
}

void check_event(char *str, char *player)
{
    int key = 0;
    int x = 0;
    int y = 0;
    int len = strlen(str);

    while (key != 32) {
        key = getch();
        if (key == 113 && find_o(player) > 1) {
            move(y, x);
            clrtoeol();
            player = swap(player, key);
            mvprintw(y, x, player);
        }
        if (key == 100 && find_o(player) < len - 2) {
            move(y, x);
            clrtoeol();
            player = swap(player, key);
            mvprintw(y, x, player);
        }
    }
}

int main(int ac, char **av)
{
    char *str = "|......................|";
    char *player = "|...........P..........|";
    int key = 0;

    initscr();
    noecho();
    initialize_game(str, player);
    check_event(str, player);
    endwin();
    return 0;
}
