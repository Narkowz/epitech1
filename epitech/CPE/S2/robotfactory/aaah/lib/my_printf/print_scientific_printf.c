/*
** EPITECH PROJECT, 2023
** print_scientific.c
** File description:
** print scientific %e
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_e(double num, int i, char sign)
{
    for (; num >= 10 || num < 1; i++) {
        if (num >= 10) {
            num /= 10;
            sign = '+';
        }
        if (num < 1) {
            num *= 10;
            sign = '-';
        }
    }
    my_printf("%f", num);
    my_putchar('e');
    my_putchar(sign);
    if (i < 10)
        my_putchar('0');
    my_put_nbr(i);
}

void print_scientific(va_list args)
{
    double num = va_arg(args, double);
    char sign = '+';
    int i = 0;

    if (num < 0) {
        num *= -1;
        my_putchar('-');
    } else if (num == 0) {
        my_putstr("0.000000e+00");
        return;
    }
    print_e(num, i, sign);
}
