/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-titouan.pradoura
** File description:
** my_delete_from_tab.c
*/

#include "my.h"

char **my_delete_from_tab(char **tab, int i)
{
    char **temp = my_alloc_tab(my_tab_len(tab));
    int encounter = 0;

    for (int j = 0; tab && tab[j]; j++) {
        if (j == i) {
            encounter = 1;
            continue;
        }
        temp[j - encounter] = my_strdup(tab[j]);
    }
    my_free_tab(tab);
    return temp;
}
