/*
** EPITECH PROJECT, 2023
** print binary
** File description:
** printf %b
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int binary[32];
    int i = 0;

    if (num == 0) {
        my_putchar('0');
        return;
    }
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_put_nbr(binary[j]);
    }
}
