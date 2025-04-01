/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr
*/

#include "../../include/my.h"

int my_putstr(char *str)
{
    int i = 0;
    char c;

    for (; str[i] != '\0'; i++) {
        c = str[i];
        my_putchar(c);
    }
    return 0;
}
