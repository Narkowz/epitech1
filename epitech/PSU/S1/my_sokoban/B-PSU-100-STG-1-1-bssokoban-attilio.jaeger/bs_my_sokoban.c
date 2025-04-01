/*
** EPITECH PROJECT, 2023
** bs_my_sokoban.c
** File description:
** main
*/

#include <ncurses.h>
#include "./include/my_sokoban.h"

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;
    char *str = av[1];
    int size = my_strlen(str);
    int key = 0;

    initscr();
    x = (COLS / 2) - (size / 2);
    y = (LINES / 2);
    mvprintw(y, x, str);
    refresh();
    while (key != 32) {
        key = getch();
    }
    endwin();
    return 0;
}
