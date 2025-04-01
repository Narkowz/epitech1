/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-titouan.pradoura
** File description:
** my_free_tab.c
*/

#include "my.h"

void my_free_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++) {
        free(tab[i]);
    }
    free(tab);
}
