/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strchr.c
*/

#include "../SRC/include/my_lib.h"

char *my_strchr(const char *s, int c)
{
    while (*s != '\0') {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    if (c == '\0') {
        return (char *)s;
    }
    return NULL;
}
