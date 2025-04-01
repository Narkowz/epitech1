/*
** EPITECH PROJECT, 2023
** print octal
** File description:
** print octal for printf
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void num_octal(int num)
{
    unsigned int unum = num;
    char octal[12];
    int i = 0;

    if (unum == 0) {
        my_put_nbr(0);
        return;
    }
    while (unum != 0) {
        octal[i] = unum % 8 + '0';
        i++;
        unum /= 8;
    }
    for (int j = i - 1; j >= 0; j--)
        my_putchar(octal[j]);
}

void print_octal(va_list args)
{
    int num = va_arg(args, int);

    num_octal(num);
}
