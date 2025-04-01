/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_strcalloc
*/

#include "my.h"

char *my_strcalloc(char *s1, char *s2)
{
    char *ret = malloc((size_t)(my_strlen(s1) + my_strlen(s2) + 2));
    int i = 0;

    for (int j = 0; s1[j]; j++) {
        ret[i] = s1[j];
        i++;
    }
    for (int j = 0; s2[j]; j++) {
        ret[i] = s2[j];
        i++;
    }
    ret[i] = '\0';
    ret[i + 1] = '\0';
    return ret;
}
