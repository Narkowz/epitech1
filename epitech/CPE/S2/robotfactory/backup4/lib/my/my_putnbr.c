/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Put all number
*/

#include "../../include/my.h"

void my_putnbr(int nb)
{
    long n;

    n = nb;
    if (n >= 0) {
        put_nbr(n);
    }
    if (n < 0 && n >= -2147483647) {
        my_putchar(45);
        put_nbr1(n);
    }
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
    }
}

int put_nbr(int n)
{
    long a;

    if (n > 9) {
        a = n / 10;
        n -= 10 * a;
        put_nbr(a);
    }
    my_putchar(n + '0');
}

int put_nbr1(int n)
{
    long a;

    a = n * -1;
    my_put_nbr(a);
}
