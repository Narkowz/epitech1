/*
** EPITECH PROJECT, 2024
** MixWord
** File description:
** main.c
*/

#include "include/mix.h"

int my_str_is_num(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 1;
    return 0;
}

int main(int ac, char **av)
{
    char **words = NULL;
    int size = 8;    

    if (gest_error(ac, av) == 84)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'f')
        words = my_str_to_word_array(opening_file(av[2]), words);
    if (ac == 5 && av[3][0] == '-' && av[3][1] == 's') {
        size = atoi(av[4]);
        if (size == 0)
            return 84;
    }
}
