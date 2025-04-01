/*
** EPITECH PROJECT, 2024
** my_paint.c
** File description:
** my_paint
*/

#include "include/my_paint.h"

int main(int ac, char **av)
{
    global_t *glob = malloc(sizeof(global_t));

    if (ac > 2) {
        free(glob);
        return 84;
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        free(glob);
        return 0;
    }
    glob->filename = NULL;
    if (ac == 2)
        glob->filename = my_strdup(av[1]);
    start_paint(glob);
    return 0;
}
