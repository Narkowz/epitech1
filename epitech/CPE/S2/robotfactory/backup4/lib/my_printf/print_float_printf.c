/*
** EPITECH PROJECT, 2023
** MY_PUTFLOAT
** File description:
** printfloat
*/

#include "../../include/my_printf.h"
#include <unistd.h>
#include <stdarg.h>

void my_float(int prec, double num, int integer, double dec)
{
    my_put_nbr(integer);
    my_putchar('.');
    if (prec > 0) {
        dec = dec < 0 ? -dec : dec;
        for (int i = 0; i < prec; i++) {
            dec *= 10;
            my_put_nbr((int)dec);
            dec -= (int)dec;
        }
    }
}

void print_floatvoid(double num)
{
    int prec = 6;
    int integer = (int)num;
    double dec = num - integer;

    if (num != num) {
        if (num > 0.0)
            my_putstr("nan");
        else
            my_putstr("-nan");
        return;
    }
    if (num == 1.0 / 0.0) {
        my_putstr("inf");
        return;
    }
    if (num == -1.0 / 0.0) {
        my_putstr("-inf");
        return;
    }
    my_float(prec, num, integer, dec);
}

void print_float(va_list args)
{
    double num = va_arg(args, double);

    print_floatvoid(num);
}
