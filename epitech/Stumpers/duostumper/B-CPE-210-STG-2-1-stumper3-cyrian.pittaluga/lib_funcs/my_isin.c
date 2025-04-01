/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_isin.c
*/

#include "../SRC/include/my_lib.h"

int my_isin(char *str, char c)
{
    if (str == NULL)
        return 0;
    while (*str) {
        if (*str == c) {
            return 1;
        }
        str++;
    }
    return 0;
}
