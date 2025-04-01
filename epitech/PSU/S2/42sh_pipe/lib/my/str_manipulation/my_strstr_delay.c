/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** strstr
*/

#include "my.h"

int my_strstr_delay(char *str, char *to_find, int pos)
{
    int len = my_strlen(to_find);
    int test = 0;

    for (int i = pos; str && str[i] && str[i] != '\0' && i < pos + len; i++) {
        test = 0;
        for (int j = 0; str[i] != '\0' && to_find[j] &&
            str[i] == to_find[j]; j++) {
            test++;
            i++;
        }
        if (test == len)
            return 1;
        i -= test;
    }
    return 0;
}
