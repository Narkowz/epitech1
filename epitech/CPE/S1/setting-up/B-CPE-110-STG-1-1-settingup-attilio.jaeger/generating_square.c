/*
** EPITECH PROJECT, 2023
** generating_square.c
** File description:
** generating_square
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/setting_up.h"

int count_number_char(char *pattern)
{
    int i = 0;

    for (i; pattern[i] != '\0'; i++);
    return i;
}

char *generateur(char *pattern, int length, char *square)
{
    int char_count = 0;
    int char_length = count_number_char(pattern);
    int i = 0;
    int count = 0;

    for (i; i < ((length * length) + length + 1) - 2; i++) {
        if (char_count == char_length)
            char_count = 0;
        if (count == length) {
            square[i] = '\n';
            count = 0;
        } else {
            square[i] = pattern[char_count];
            char_count++;
            count++;
        }
    }
    square[i] = '\0';
    return square;
}

char *generating_square(char *map, char **av, int ac, char *pattern)
{
    int length = get_nbr(av);
    char *square = malloc((length * length) + length + 1);

    if (pattern[0] == '\0')
        exit(84);
    square[(length * length) + length] = '\0';
    square = generateur(pattern, length, square);
    return square;
}
