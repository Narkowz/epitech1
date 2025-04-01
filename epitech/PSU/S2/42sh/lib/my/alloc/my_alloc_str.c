/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-titouan.pradoura
** File description:
** my_alloc_str.c
*/

#include "my.h"

char *my_alloc_str(int size)
{
    char *alloc = malloc(sizeof(char) * (long unsigned int)(size + 1));

    for (int i = 0; i <= size; i++)
        alloc[i] = '\0';
    return alloc;
}
