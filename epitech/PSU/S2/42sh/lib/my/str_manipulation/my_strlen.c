/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** return the len of an str
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str && str[i] != '\0') {
        i++;
    }
    return i;
}
