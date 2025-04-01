/*
** EPITECH PROJECT, 2023
** MY_PUTFLOAT
** File description:
** printfloat
*/

#include "../../include/my_printf.h"
#include <unistd.h>
#include <stdarg.h>

void print_floatvoidup(double num)
{
    int prec = 6;
    int integer = (int)num;
    double dec = num - integer;

    if (num != num) {
        if (num > 0.0)
            my_putstr("NAN");
        else
            my_putstr("-NAN");
        return;
    }
    if (num == 1.0 / 0.0) {
        my_putstr("INF");
        return;
    }
    if (num == -1.0 / 0.0) {
        my_putstr("-INF");
        return;
    }
    my_float(prec, num, integer, dec);
}

void print_floatup(va_list args)
{
    double num = va_arg(args, double);

    print_floatvoidup(num);
}
