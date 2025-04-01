/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_tab_len.c
*/

#include "my.h"

int my_tab_len(char **tab)
{
    int len = 0;

    if (tab == NULL)
        return 0;
    for (len = 0; tab && tab[len]; len++);
    return len;
}
