/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strdup.c
*/

#include "../SRC/include/my_lib.h"

char *my_strndup(const char *str, size_t n)
{
    char *new_str;
    size_t len = my_strlen(str);

    if (n < len)
        len = n;
    new_str = (char *)malloc(len + 1);
    if (new_str == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return new_str;
}
