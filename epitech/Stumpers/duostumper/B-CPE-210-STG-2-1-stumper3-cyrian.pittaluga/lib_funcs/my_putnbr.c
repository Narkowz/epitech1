/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_putnbr.c
*/

#include "../SRC/include/my_lib.h"

void my_putnbr(int n)
{
    if (n == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n / 10) {
        my_putnbr(n / 10);
    }
    my_putchar(n % 10 + '0');
}
