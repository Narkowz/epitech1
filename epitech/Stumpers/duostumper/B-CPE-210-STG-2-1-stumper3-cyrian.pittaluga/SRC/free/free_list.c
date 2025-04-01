/*
** EPITECH PROJECT, 2024
** free_list.c
** File description:
** Game Of Life
*/

#include "../include/my_lib.h"
#include "../include/game_of_life.h"

void free_list(char *raw_map, char **map)
{
    if (raw_map != NULL)
        free(raw_map);
    if (map != NULL) {
        for (int i = 0; map[i] != NULL; i++)
            free(map[i]);
        free(map);
    }
}
