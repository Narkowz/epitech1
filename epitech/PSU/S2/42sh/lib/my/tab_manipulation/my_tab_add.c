/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_tab_add.c
*/

#include "my.h"

char **my_tab_add(char **tab, char *add)
{
    int size = my_tab_len(tab) + 2;
    int i = 0;
    char **temp = malloc(sizeof(char *) * (long unsigned int)(size));

    if (tab)
        for (i = 0; tab[i]; i++)
            temp[i] = my_strdup(tab[i]);
    if (add) {
        temp[i] = my_strdup(add);
        temp[i + 1] = NULL;
    } else
        temp[i] = NULL;
    return temp;
}
