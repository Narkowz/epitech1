/*
** EPITECH PROJECT, 2024
** my_navy.c
** File description:
** my_navy
*/

#include "include/my.h"
#include "include/my_navy.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (testing_file(av[1]) == 0)
        // launch_game();
    return 0;
}
