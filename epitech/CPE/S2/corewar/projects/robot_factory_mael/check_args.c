/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "../my/my.h"

int check_args(int ac, char **av)
{
    int len;

    if (ac != 2)
        return 84;
    len = my_strlen(av[1]);
    if (av[1][len - 2] != '.' || av[1][len - 1] != 's')
        return 84;
    return 0;
}
