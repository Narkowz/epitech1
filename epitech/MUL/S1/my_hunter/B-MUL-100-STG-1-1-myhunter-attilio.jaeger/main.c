/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "include/my.h"

void main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            help_flag();
        } else {
            mini_printf("Invalid flag : '%s'", av[1]);
        }
    } else {
        create_window();
    }
}
