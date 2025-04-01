/*
** EPITECH PROJECT, 2024
** GameOfLife
** File description:
** Game of Life
*/

#include "../include/game_of_life.h"

void check_map_characters(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (my_isin("X.\n", map[i]) == 0) {
            my_puterror("Unsupported character in map file :");
            my_puterror(&map[i]);
            my_puterror("\n");
            free_list(map, NULL);
            exit(84);
        }
    }
}
