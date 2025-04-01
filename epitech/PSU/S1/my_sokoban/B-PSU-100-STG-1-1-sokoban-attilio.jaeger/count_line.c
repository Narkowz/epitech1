/*
** EPITECH PROJECT, 2023
** count_line.c
** File description:
** count_line
*/

#include "include/my_sokoban.h"

int line_len(char *player, int pos)
{
    int i = 0;
    int j = 0;

    for (i; player[pos - i] != '\n'; i++);
    for (j; player[pos + j] != '\n'; j++);
    return j + i - 1;
}

int line_len_up(char *player, int pos)
{
    int i = 0;
    int j = 0;

    for (i = pos; player[i] != '\n'; i--);
    i--;
    for (j; player[i - j] != '\n' && i - j != 0; j++);
    return j + 1;
}
