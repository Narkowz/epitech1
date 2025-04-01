/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** get nbr
*/

#include "../../include/my.h"

int my_getnbr(char *av)
{
    int number = 0;
    int i = 0;

    while (av[i] != '\0') {
        if (av[i] >= 48 && av[i] <= 57)
            number = number * 10 + (av[i] - '0');
        i++;
    }
    return number;
}
