/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strcspn.c
*/

#include "../SRC/include/my_lib.h"

static int char_exists_in_string(const char c, const char *str)
{
    while (*str != '\0') {
        if (c == *str) {
            return 1;
        }
        str++;
    }
    return 0;
}

size_t my_strcspn(const char *s, const char *reject)
{
    const char *p = s;

    while (*p != '\0') {
        if (char_exists_in_string(*p, reject)) {
            return (p - s);
        }
        p++;
    }
    return (p - s);
}
