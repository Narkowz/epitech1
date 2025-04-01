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
    int count = 6;
    int n = 4;

    while (count >= n) {
        num /= 10;
        count--;
    }
    my_put_nbr(num);
}
