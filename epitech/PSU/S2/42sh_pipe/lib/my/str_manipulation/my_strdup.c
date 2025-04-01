/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** allocate memory to an str
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int len = 0;

    if (!src)
        return NULL;
    while (src[len])
        len++;
    dest = my_alloc_str(len);
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}
