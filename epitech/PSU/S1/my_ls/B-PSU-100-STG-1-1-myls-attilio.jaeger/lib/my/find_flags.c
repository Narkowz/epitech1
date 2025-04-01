/*
** EPITECH PROJECT, 2023
** find_flags.c
** File description:
** find_flags
*/

#include "../../include/my.h"
#include <stdio.h>

int identifier_flags(char **flags, int i, int ac)
{
    switch (flags[i][1]) {
    case 'r':
        sort_by_reverse(flags, i, ac);
        break;
    case 'a':
        print_list_a(flags, i, ac);
        break;
    default:
        mini_printf("ls: invalid option -- '%c'\n", flags[i][1]);
        mini_printf("Try 'ls --help' for more information.\n");
        return 2;
        break;
    }
}

int find_flags(int ac, char **str, int i)
{
    for (; i < ac; i++) {
        if (str[i][0] == '-') {
            identifier_flags(str, i, ac);
            return 1;
        } else {
            return 0;
        }
    }
}
