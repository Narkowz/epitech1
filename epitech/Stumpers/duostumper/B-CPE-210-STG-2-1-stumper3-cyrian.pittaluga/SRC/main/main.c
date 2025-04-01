/*
** EPITECH PROJECT, 2024
** Game of Life
** File description:
** Game of Life
*/

#include "../include/my_lib.h"
#include "../include/game_of_life.h"

int main(int argc, char **argv)
{
    char *raw_map = NULL;
    char **map = NULL;

    if (argc != 3) {
        my_putstr("Usage ; ./gameoflife initial_map NumberOfIteration\n");
        return 84;
    }
    raw_map = opening_file(argv[1]);
    check_map_characters(raw_map);
    map = my_str_to_word_array(raw_map, map);
    if (map == NULL) {
        my_puterror("my_str_to_word_array failed");
        free_list(raw_map, map);
        return 84;
    }
    check_map_format(raw_map, map);
    map = cells_handling(map, my_atoi(argv[2]));
    print_map(map);
    free_list(raw_map, map);
    return 0;
}
