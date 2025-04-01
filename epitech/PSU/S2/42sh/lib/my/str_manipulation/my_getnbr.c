/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** return the number contained in a str
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i++;
    }
    if (str[i])
        return -1;
    return (int)(nb);
}
