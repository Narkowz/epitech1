/*
** EPITECH PROJECT, 2023
** print int
** File description:
** print int
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_int(va_list args)
{
    int num = va_arg(args, int);

    my_put_nbr(num);
}
