/*
** EPITECH PROJECT, 2023
** get_nbr.c
** File description:
** get_nbr
*/

#include "../../include/organized.h"

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
