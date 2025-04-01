/*
** EPITECH PROJECT, 2024
** geekNameFormatter.c
** File description:
** geekNameFormatter
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (av[1])
        start_program(av[1]);
    else {
        write(2, "Usage: geekNameFormatter string", 32);
        write(2, "\n", 1);
        return 84;
    }
    return 0;
}
