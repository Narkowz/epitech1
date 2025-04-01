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
char **my_str_to_word_array(char *env, char **path);
void free_list(char *raw_map, char **map);

#endif
