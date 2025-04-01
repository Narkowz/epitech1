/*
** EPITECH PROJECT, 2024
** game_of_life.h
** File description:
** Game of life
*/

#ifndef GAME_OF_LIFE_H
    #define GAME_OF_LIFE_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "../include/my_lib.h"

char *opening_file(char *path);
void check_map_characters(char *map);
void check_map_format(char *raw_map, char **map);
char **my_str_to_word_array(char *env, char **path);
void print_map(char **map);
void free_list(char *raw_map, char **map);
int get_neighbor_nbr(char **map, int x, int y);
char **cells_handling(char **map, int nb_iteration);
int count_lines(char **map);

#endif
