/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strcat.c
*/

#include "../SRC/include/my_lib.h"

char *my_strcat(char *dest, const char *src)
{
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}
