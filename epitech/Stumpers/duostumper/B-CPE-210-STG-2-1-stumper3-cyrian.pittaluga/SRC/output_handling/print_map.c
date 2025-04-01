/*
** EPITECH PROJECT, 2024
** GameOfLife
** File description:
** writes the map to the stdout
*/

#include "../include/game_of_life.h"

void print_map(char **map)
{
    if (map == NULL) {
        my_puterror("print map: A NULL pointer was passed as argument");
        exit(84);
    }
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putstr("\n");
    }
}
