/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strcmp.c
*/

#include "../SRC/include/my_lib.h"

int my_strcmp(const char *str1, const char *str2)
{
    if (str1 == NULL && str2 != NULL)
        return -1;
    if (str1 != NULL && str2 == NULL)
        return -1;
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}
