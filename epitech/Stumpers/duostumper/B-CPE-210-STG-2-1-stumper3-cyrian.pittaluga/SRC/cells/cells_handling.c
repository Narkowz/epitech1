/*
** EPITECH PROJECT, 2024
** cells_handling.c
** File description:
** Game of Life
*/

#include "../include/game_of_life.h"

char **copy_tab(char **map)
{
    char **temp = malloc(sizeof(char *) * count_lines(map));
    int i = 0;

    for (; i < count_lines(map); i++)
        temp[i] = my_strdup(map[i]);
    temp[i] = NULL;
    return temp;
}

char **update_cell(char **new_map, char **map, int i, int j)
{
    int neighbor_nbr = get_neighbor_nbr(map, i, j);

    if (map[i][j] == '.') {
        if (neighbor_nbr == 3) {
            new_map[i][j] = 'X';
            return new_map;
        }
    }
    if (map[i][j] == 'X') {
        if (neighbor_nbr == 0 || neighbor_nbr == 1) {
            new_map[i][j] = '.';
            return new_map;
        }
        if (neighbor_nbr >= 4 && neighbor_nbr <= 8) {
            new_map[i][j] = '.';
            return new_map;
        }
    }
    return new_map;
}

char **iterate_through_tab(char **map)
{
    int i = 0;
    char **temp_map = copy_tab(map);

    for (; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            print_map(temp_map);
            printf("\n\n");
            temp_map = update_cell(temp_map, map, i, j);
        }
    return temp_map;
}

char **cells_handling(char **map, int nb_iteration)
{
    int i = 0;
    char **new_map = NULL;

    for (; i < nb_iteration; i++) {
        printf("tyest\n");
        new_map = iterate_through_tab(map);
        free_list(NULL, map);
        map = new_map;
        print_map(map);
        printf("\n");
    }
    return map;
}
