/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** get nbr
*/

#include "../../include/my.h"

int get_nbr(char *av)
{
    int number = 0;
    int i = 0;

    while (av[i] != '\0') {
        number = number * 10 + (av[i] - '0');
        i++;
    }
    return number;
}
