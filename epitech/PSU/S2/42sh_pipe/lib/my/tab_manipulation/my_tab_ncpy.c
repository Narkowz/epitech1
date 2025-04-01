/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_tab_ncpy.c
*/

#include "my.h"

char **my_tab_ncpy(char **tab, int n)
{
    int tab_len = my_tab_len(tab);
    char **temp;

    if (n > tab_len)
        temp = malloc(sizeof(char *) * (long unsigned int)(n + 1));
    else
        temp = malloc(sizeof(char *) * (long unsigned int)(tab_len + 1));
    for (int i = 0; tab[i] && i < n; i++) {
        temp[i] = my_strdup(tab[i]);
    }
    return temp;
}
