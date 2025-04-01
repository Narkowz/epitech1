/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "./include/my.h"

int main(int ac, char **av)
{
    int error;
    int i = 1;

    if (ac == 1) {
        my_simple_ls(".");
        return (0);
    }
    for (i; i < ac; i++) {
        error = error_handling(av[i]);
        if (error != 0)
            return (error);
    }
    i = 1;
    for (i; i < ac; i++) {
        if (find_flags(ac, av, i) != 0) {
            break;
        } else
            my_simple_ls(av[i]);
    }
    return (0);
}
