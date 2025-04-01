/*
** EPITECH PROJECT, 2023
** print string
** File description:
** print string
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_string(va_list args)
{
    char *str = va_arg(args, char *);

    my_putstr(str);
}
