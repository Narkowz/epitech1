/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-titouan.pradoura
** File description:
** my_print_tab.c
*/

#include "my.h"

void my_print_tab(char **tab, int fd)
{
    for (int i = 0; tab && tab[i]; i++) {
        my_putstr(tab[i], fd);
        my_putchar('\n', fd);
    }
}
