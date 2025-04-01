/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** putstring
*/

#include "../../include/my.h"

int my_putstr(char *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return 0;
}
