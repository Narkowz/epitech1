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
    char *result = my_alloc_str(len);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (i != index) {
            result[j] = str[i];
            j++;
        }
    }
    free(str);
    return result;
}
