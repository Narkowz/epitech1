/*
** EPITECH PROJECT, 2023
** operating_square.c
** File description:
** operating_square
*/

#include <stdio.h>
#include "./include/setting_up.h"

int compare_digits(int **int_map, int y, int x)
{
    int highest_digits = 0;

    if (int_map[y][x] == (-1)) {
        highest_digits = int_map[y][x];
        return highest_digits;
    }
    if (int_map[y][x - 1] < int_map[y - 1][x - 1]) {
        highest_digits = int_map[y][x - 1];
    } else if (int_map[y - 1][x - 1] < int_map[y - 1][x]) {
        highest_digits = int_map[y - 1][x - 1];
    } else {
        highest_digits = int_map[y - 1][x];
    }
    return highest_digits;
}

void operating_square(int **int_map, char **twod_map)
{
    int lines = count_lines(twod_map);
    int cols = count_cols(twod_map);
    int x = 1;
    int y = 1;
    int k = 0;
    int f = 0;
    int highest_digits = 0;

    for (y; y < lines; y++) {
        x = 1;
        for (x; x < cols; x++) {
            highest_digits = compare_digits(int_map, y, x);
            int_map[y][x] = highest_digits + 1;
        }
    }
}
