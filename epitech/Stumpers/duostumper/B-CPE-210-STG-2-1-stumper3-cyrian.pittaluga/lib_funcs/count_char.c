/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** count_char.c
*/

#include "../SRC/include/my_lib.h"

int my_get_char_count(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count += 1;
    }
    return count;
}
