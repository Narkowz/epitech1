/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** str str
*/

#include "../../include/my.h"

int temp_for(char *str, char *to_find, int i, int to_find_len)
{
    int j = 0;

    for (; j < to_find_len; j++) {
        if (str[i + j] != to_find[j])
            break;
    }
    return j;
}

char *my_strstr(char *str, char *to_find)
{
    int to_find_len = 0;
    int str_len = 0;
    int j = 0;

    if (str == NULL)
        return to_find;
    if (to_find == NULL)
        return NULL;
    to_find_len = my_strlen(to_find);
    str_len = my_strlen(str);
    for (int i = 0; i <= str_len - to_find_len; i++) {
        j = temp_for(str, to_find, i, to_find_len);
        if (j == to_find_len)
            return &str[i];
    }
    return NULL;
}
