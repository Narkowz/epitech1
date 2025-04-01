/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main
*/

#include "../my/my.h"

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    if ((ac == 2 && my_strcmp(av[1], "-h") == 0))
        return (print_h());
    return (check_args);
}
