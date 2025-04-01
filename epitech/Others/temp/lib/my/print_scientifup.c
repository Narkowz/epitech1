/*
** EPITECH PROJECT, 2023
** print_scientifup
** File description:
** print scientific %E
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_eup(double num, int i, char sign)
{
    my_printf("%f", num);
    my_putchar('E');
    my_putchar(sign);
    if (i < 10)
        my_putchar('0');
    my_put_nbr(i);
}

void print_scientifup(va_list args)
{
    double num = va_arg(args, double);
    char sign = '+';
    int i = 0;

    if (num < 0) {
        num *= -1;
        my_putchar('-');
    }
    for (;num >= 10 || num < 1; i++) {
        if (num >= 10) {
            num /= 10;
            sign = '+';
        }
        if (num < 1) {
            num *= 10;
            sign = '-';
        }
    }
    print_eup(num, i, sign);
}
