/*
** EPITECH PROJECT, 2023
** check_loose.c
** File description:
** check_loose
*/

#include <ncurses.h>
#include "include/my_sokoban.h"

int check_loose(char *string)
{
    int count = 0;
    int counter = 0;
    int i = 0;

    for (i; string[i] != '\0'; i++) {
        if (string[i] == 'X') {
            count++;
        }
        if (string[i] == 'X' &&
        ((string[i - 1] == '#' && string[i - line_len_up(string, i)] == '#') ||
        (string[i + 1] == '#' && string[i - line_len_up(string, i)] == '#') ||
        (string[i - 1] == '#' && string[i + line_len(string, i) + 1] == '#') ||
        (string[i + 1] == '#' && string[i + line_len(string, i) + 1] == '#')))
            counter += 1;
    }
    if (count == counter) {
        refresh();
        return 1;
    }
    return 5;
}
