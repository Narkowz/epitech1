/*
** EPITECH PROJECT, 2024
** my_isalphanumeric.c
** File description:
** my_isalphanumeric
*/

#include "my.h"


int my_isalphanumeric(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}
