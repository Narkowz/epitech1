/*
** EPITECH PROJECT, 2023
** prepare_square.c
** File description:
** prepare_square
*/

#include <stdlib.h>
#include <stdio.h>
#include "./include/setting_up.h"

int count_lines(char **map)
{
    int lines = 0;

    while (map[lines] != NULL) {
        if (map[lines][0] == '\0')
            break;
        lines++;
    }
    return lines;
}

int count_cols(char **map)
{
    int cols = 0;

    while (map[0][cols] != '\0') {
        cols++;
    }
    return cols;
}

static int int_first_line_x(char **map, int **int_map)
{
    int x;

    for (x = 0; map[0][x] != '\0'; x++) {
        if (map[0][x] == '.') {
            int_map[0][x] = 1;
        } else {
            int_map[0][x] = 0;
        }
    }
    return x;
}

static int int_first_line_y(char **map, int **int_map, int lines)
{
    int y = 0;

    for (y; y < lines; y++) {
        if (map[y][0] == '.') {
            int_map[y][0] = 1;
        } else {
            int_map[y][0] = 0;
        }
    }
    return y;
}

static int **for_if(int **int_map, int y, int x, char **map)
{
    if (map[y][x] == 'o') {
        int_map[y][x] = (-1);
    }
    if (map[y][x] == '.') {
        int_map[y][x] = 1;
    }
}

int vesqui_full_o(char **map, int **int_map, int lines, int cols)
{
    int y = 1;
    int x = 1;

    for (y; y < lines; y++) {
        x = 1;
        for (x; x < cols; x++) {
            for_if(int_map, y, x, map);
        }
    }
}

int **prepare_square(char **map)
{
    data_t data;
    int **int_map = NULL;
    int i = 0;
    int x;

    data.lines = count_lines(map);
    data.cols = count_cols(map);
    int_map = malloc(sizeof(int *) * data.lines);
    for (i; i < data.lines; i++) {
        int_map[i] = (int *)malloc(sizeof(int) * data.cols);
    }
    x = int_first_line_x(map, int_map);
    int_first_line_y(map, int_map, data.lines);
    vesqui_full_o(map, int_map, data.lines, data.cols);
    return int_map;
}
