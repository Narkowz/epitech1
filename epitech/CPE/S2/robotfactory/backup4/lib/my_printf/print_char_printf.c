/*
** EPITECH PROJECT, 2023
** print char
** File description:
** print char for printf
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_char(va_list args)
{
    char c = va_arg(args, int);

    my_putchar(c);
}
