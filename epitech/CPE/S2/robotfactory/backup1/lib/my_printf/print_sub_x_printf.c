/*
** EPITECH PROJECT, 2023
** print_sub_x.c
** File description:
** print sub x #
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_sub_x(va_list args, const char *format, int *i)
{
    if (format[1] == 'x')
        my_putstr("0x");
    if (format[1] == 'X')
        my_putstr("0X");
}
