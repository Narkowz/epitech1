/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** putstring
*/

#include <unistd.h>
#include "../../include/organized.h"

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return 0;
}
