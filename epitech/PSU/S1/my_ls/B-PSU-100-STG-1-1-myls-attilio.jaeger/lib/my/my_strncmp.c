/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** my_strncmp
*/

#include <stdlib.h>
#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
        i++;
    return (i);
}
