/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** append
*/

#include "my.h"

void append(char ***arr, char *new_str)
{
    int count = 0;
    char **new_arr;

    while ((*arr)[count] != NULL)
        count++;
    new_arr = malloc((size_t)((count + 2) * (int)sizeof(char *)));
    for (int i = 0; i < count; i++)
        new_arr[i] = (*arr)[i];
    new_arr[count] = my_strdup(new_str);
    new_arr[count + 1] = NULL;
    *arr = new_arr;
}
