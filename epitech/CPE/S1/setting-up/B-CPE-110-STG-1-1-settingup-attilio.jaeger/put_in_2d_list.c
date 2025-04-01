/*
** EPITECH PROJECT, 2023
** setting_up.c
** File description:
** setting_up
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/setting_up.h"

int number_of_lines(char *map)
{
    int i = 0;
    int num_lines = 1;

    for (i; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            num_lines++;
        }
    }
    return (num_lines);
}

char *allocate_line_memory(char *line, int char_count)
{
    char *new_line = malloc((char_count + 1) * sizeof(char));

    if (new_line == NULL) {
        mini_printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    if (line != NULL) {
        for (int i = 0; i < char_count; i++) {
            new_line[i] = line[i];
        }
        free(line);
    }
    new_line[char_count] = '\0';
    return new_line;
}

static void assign(char *line, int char_count, char **twod_map, int line_index)
{
    line = allocate_line_memory(line, char_count);
    twod_map[line_index] = line;
}

static void function_for(char *map, char **twod_map)
{
    int line_index = 0;
    int char_count = 0;
    char *line = NULL;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            assign(line, char_count, twod_map, line_index++);
            line = NULL;
            char_count = 0;
        } else {
            line = allocate_line_memory(line, char_count);
            line[char_count] = map[i];
            char_count++;
        }
    }
    assign(line, char_count, twod_map, line_index);
    twod_map[line_index + 1] = NULL;
}

char **put_in_2d_list(char *map)
{
    int num_lines;
    char **twod_map;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '.' && map[i] != 'o' && map[i] != '\0' && map[i] != '\n')
            exit(84);
    }
    num_lines = number_of_lines(map);
    twod_map = malloc((num_lines + 1) * sizeof(char *));
    if (twod_map == NULL)
        exit(84);
    function_for(map, twod_map);
    return twod_map;
}

void print_2d(char **twod_map)
{
    for (int i = 0; i < count_lines(twod_map); i++) {
        write(1, twod_map[i], count_cols(twod_map));
        mini_printf("\n");
    }
}

void free_2d_map(char **twod_map)
{
    for (int i = 0; twod_map[i] != NULL; i++) {
        free(twod_map[i]);
    }
    free(twod_map);
}
