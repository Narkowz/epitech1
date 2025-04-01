/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** allocated memory
*/

#include <stdlib.h>
#include "../../include/my_sokoban.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    while (src[i] != '\0')
        i++;
    str = malloc((sizeof(char) * i) + 1);
    str[i] = '\0';
    while (i != -1) {
        str[i] = src[i];
        i--;
    }
    return (str);
}
