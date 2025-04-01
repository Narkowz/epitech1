/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** add_char.c
*/

#include "my.h"

char *add_char(char *str, int index, char c)
{
    char *temp = my_alloc_str(my_strlen(str) + 1);
    int i = 0;

    for (i = 0; str && str[i] && i < index; i++)
        temp[i] = str[i];
    temp[i] = c;
    for (int y = 0; str && str[i + y]; y++) {
        temp[y + i + 1] = str[i + y];
    }
    free(str);
    return temp;
}
