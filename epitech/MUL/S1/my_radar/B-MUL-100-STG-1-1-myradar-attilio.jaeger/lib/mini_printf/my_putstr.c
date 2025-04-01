/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** putstring
*/

#include "../../include/my_radar.h"

int my_putstr(char const *str)
{
    int i = 0;
    char c;

    for (; str[i] != '\0'; i++) {
        c = str[i];
        my_putchar(c);
    }
    return 0;
}
