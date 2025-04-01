/*
** EPITECH PROJECT, 2023
** my_radar.c
** File description:
** my_radar
*/

#include "include/my_radar.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (ac == 2 && allowed_file(av[1]) == 0)
        start_game(av[1]);
    else
        return 84;
}
