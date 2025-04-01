/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** delete_char.c
*/

#include "my.h"

char *delete_char(char *str, int index)
{
    int len = my_strlen(str);
    char *result;

    result = my_alloc_str(1024);
    for (int i = 0; str[i] && i < index && i < len; i++)
        result[i] = str[i];
    for (int i = index + 1; str[i] && i < len; i++)
        result[i - 1] = str[i];
    free(str);
    return result;
}
