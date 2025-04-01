/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** rev str
*/

#include "../../include/my.h"

int my_strlen_bis(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    int len = my_strlen_bis(str);
    int j = len;
    int i = 0;
    char tmp;

    for (; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[j - 1];
        str[j - 1] = tmp;
        j--;
    }
    return (str);
}
