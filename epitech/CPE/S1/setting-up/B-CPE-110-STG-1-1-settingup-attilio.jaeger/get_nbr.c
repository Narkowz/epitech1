/*
** EPITECH PROJECT, 2023
** get_nbr.c
** File description:
** get_nbr
*/

#include "./include/setting_up.h"

int get_nbr(char **av)
{
    int number = 0;
    int i = 0;

    while (av[1][i] != '\0') {
        number = number * 10 + (av[1][i] - '0');
        i++;
    }
    return number;
}
