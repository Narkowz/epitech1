/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strlen.c
*/

#include "../SRC/include/my_lib.h"

int my_strlen(const char *str)
{
    int length = 0;

    if (str == NULL)
        return 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
