/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include <stdlib.h>

char *my_strrchr(const char *s, int c)
{
    char *last_occurrence = NULL;

    while (*s != '\0') {
        if (*s == c)
            last_occurrence = (char *)s;
        s++;
    }
    return last_occurrence;
}
