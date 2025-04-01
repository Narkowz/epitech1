/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** get nbr
*/

#include "../include/need4stek.h"

int my_getnbr(char *av)
{
    int number = 0;
    int i = 0;
    int comma = 0;

    while (av[i] != '\0') {
        if (av[i] == '.')
            comma = 1;
        if (comma == 0)
            number = number * 10 + (av[i] - '0');
        else
            number = number + ((av[i] - '0') / 10);
        i++;
    }
    return number;
}
