/*
** EPITECH PROJECT, 2023
** setting_up.c
** File description:
** setting_up
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./include/setting_up.h"
#include <stdio.h>

int get_nbr_biss(char *av)
{
    int number = 0;
    int i = 0;

    while (av[i] != '\0') {
        number = number * 10 + (av[i] - '0');
        i++;
    }
    return number;
}

int test_pattern(char *pattern)
{
    int i = 0;
    int k = 0;

    for (k; pattern[k] != '\0'; k++) {
        if (pattern[k] < '0' || pattern[k] > '9')
            exit(84);
    }
    i = get_nbr_biss(pattern);
    if (i <= 0)
        exit(84);
}

void main(int ac, char **av)
{
    char *map = malloc(100 * sizeof(char));
    int i = 0;
    char *pattern = av[2];
    char **twod_map;
    int **int_map;

    if (ac == 3) {
        test_pattern(av[1]);
        map = generating_square(map, av, ac, pattern);
    } else {
        map = opening_file(av[1]);
    }
    twod_map = put_in_2d_list(map);
    int_map = prepare_square(twod_map);
    operating_square(int_map, twod_map);
    twod_map = find_square(twod_map, int_map);
    free_2d_map(twod_map);
}
