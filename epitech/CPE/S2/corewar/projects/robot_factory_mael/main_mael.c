/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "../my/my.h"

int asm_fct(int ac, char **av)
{
    if (check_args(ac, av) == 84)
        return 84;
    for (int i = 1; i < ac; i++) {
        if (validate_file(av[i], av) == 84)
            return 84;
    }
    return (create_cor(ac, av));
}
