/*
** EPITECH PROJECT, 2023
** word_to_str.c
** File description:
** word_to_str
*/

#include "./include/setting_up.h"
#include <stdlib.h>

void word_to_str(char **map)
{
    int lines = count_lines(map);
    int cols = count_cols(map);
    char *map_char = malloc((cols * lines) + cols + 1);
    int x = 0;
    int y = 0;
    int k = 0;

    for (y; y != count_lines(map); y++) {
        for (x = 0; x != count_cols(map); x++) {
            map_char[k] = map[y][x];
            k++;
        }
        map_char[k] = '\n';
        k++;
    }
    map[(cols * lines) + cols + 1] = '\0';
    write(1, map_char, (cols * lines) + cols);
}