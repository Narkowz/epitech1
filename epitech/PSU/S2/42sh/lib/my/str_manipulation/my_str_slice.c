/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_str_slice.c
*/

#include "my.h"

char *my_str_slice(char *line, int start, int end)
{
    char *temp = NULL;

    if (end < start && !line)
        return NULL;
    temp = my_alloc_str(end - start + 1);
    for (int i = start; line[i] && i <= end; i++)
        temp[i - start] = line[i];
    return temp;
}
