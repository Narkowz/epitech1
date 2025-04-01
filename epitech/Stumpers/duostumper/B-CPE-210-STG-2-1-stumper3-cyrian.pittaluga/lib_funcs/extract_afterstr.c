/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** extract_afterstr.c
*/

#include "../SRC/include/my_lib.h"

char *extract_after_char(const char *str, char c)
{
    char *pos = my_strchr(str, c);

    if (pos != NULL) {
        return pos + 1;
    } else {
        return NULL;
    }
}
