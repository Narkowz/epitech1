/*
** EPITECH PROJECT, 2023
** find_square.c
** File description:
** find_square
*/

#include "./include/setting_up.h"
#include <stdio.h>

int highest_possible_square(int **int_map, int x, int y, data_t *data)
{
    if (int_map[y][x] > data->highest) {
        data->highest = int_map[y][x];
        data->a = y;
        data->b = x;
    }
    return data->highest;
}

char **print_x_square(char **map, data_t *data)
{
    int x = (data->b + 1) - data->highest;
    int y = (data->a + 1) - data->highest;

    for (y; y <= data->a; y++) {
        x = (data->b + 1) - data->highest;
        for (x; x <= data->b; x++) {
            map[y][x] = 'x';
        }
    }
    print_2d(map);
    return map;
}

char **find_square(char **map, int **int_map)
{
    int lines = count_lines(map);
    int cols = count_cols(map);
    int x = 0;
    int y = 0;
    data_t data;

    data.b = 0;
    data.a = 0;
    data.highest = 0;
    for (y; y < lines; y++) {
        x = 0;
        for (x; x < cols; x++) {
            data.highest = highest_possible_square(int_map, x, y, &data);
        }
    }
    map = print_x_square(map, &data);
    return map;
}
