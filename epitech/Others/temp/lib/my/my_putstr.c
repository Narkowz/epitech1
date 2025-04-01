/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** pustr
*/

#include "../../include/my_printf.h"
#include <unistd.h>

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
