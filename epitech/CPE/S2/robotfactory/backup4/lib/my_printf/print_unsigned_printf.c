/*
** EPITECH PROJECT, 2023
** print unsigned
** File description:
** print unsigned
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void my_put_unsigned(unsigned int num)
{
    if (num >= 10) {
        my_put_unsigned(num / 10);
    }
    my_putchar('0' + num % 10);
}

void my_put_nb(int num)
{
    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    my_put_unsigned((unsigned int)num);
}

void print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);

    if (num < 0) {
        num = ~0u - (unsigned int)(-num) + 1;
    }
    my_put_unsigned(num);
}

//en gros le ~0u permet d'inverser les bits
//genre 0 = 1 pour afficher la valeur maximale
//pour un unsigned int
