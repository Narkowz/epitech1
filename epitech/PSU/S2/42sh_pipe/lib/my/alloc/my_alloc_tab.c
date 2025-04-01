/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_alloc_tab.c
*/

#include "my.h"

char **my_alloc_tab(int size)
{
    char **temp = malloc(sizeof(char *) * (long unsigned int)(size + 1));

    for (int i = 0; i <= size; i++)
        temp[i] = NULL;
    return temp;
}
