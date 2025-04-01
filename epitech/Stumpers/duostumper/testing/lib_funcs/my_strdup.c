/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strdup.c
*/

#include "../SRC/include/my_lib.h"

char *my_strdup(const char *str)
{
    size_t len = my_strlen(str) + 1;
    char *new_str = (char *)malloc(len);

    if (new_str == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
