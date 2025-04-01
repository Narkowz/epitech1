/*
** EPITECH PROJECT, 2024
** get_neighbor_nbr.c
** File description:
** Game of Life
*/

#include "../include/game_of_life.h"

int count_lines(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i++);
    return i;
}

int iterate_through_x(int j, int i, int x, char **map)
{
    int count = 0;

    while (j <= x + 1) {
        if (j < 0)
            j++;
        if (j > my_strlen(map[i]))
            break;
        if (map[i][j] == 'X')
            count++;
        j++;
    }
    return count;
}

int get_neighbor_nbr(char **map, int x, int y)
{
    int count = 0;
    int i = y - 1;
    int j = x - 1;

    while (i <= y + 1) {
        if (i < 0)
            i++;
        if (i > count_lines(map) - 1)
            break;
        j = x - 1;
        if (iterate_through_x(j, i, x, map) != 0)
            count += iterate_through_x(j, i, x, map);
        i++;
    }
    return count;
}
