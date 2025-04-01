/*
** EPITECH PROJECT, 2024
** Libs
** File description:
** my_arrdup
*/

#include "my.h"

long unsigned int countlines(char **arr)
{
    long unsigned int i = 0;

    for (; arr[i]; i++);
    return i;
}

char **my_arrdup(char **arr)
{
    long unsigned int lines = countlines(arr);
    char **new = NULL;

    if (lines == 0)
        return NULL;
    new = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0; arr[i]; i++)
        new[i] = my_strdup(arr[i]);
    new[lines] = NULL;
    return new;
}
