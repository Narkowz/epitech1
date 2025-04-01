/*
** EPITECH PROJECT, 2024
** GameOfLife
** File description:
** check that each line's length is the same.
*/

#include "../include/game_of_life.h"

void check_map_format(char *raw_map, char **map)
{
    int length = my_strlen(map[0]);

    for (int i = 1; map[i] != NULL; i++) {
        if (length != my_strlen(map[i])) {
            my_puterror("Bad format: ");
            my_puterror("Uneven line lengths in initial map at line: ");
            my_putnbr(i + 1);
            my_puterror("\n");
            free_list(raw_map, map);
            exit(84);
        }
    }
}
