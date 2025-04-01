/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include <stdlib.h>

char *my_strchr(const char *s, int c)
{
    while (*s != '\0') {
        if (*s == c)
            return (char *)s;
        s++;
    }
    return NULL;
}
