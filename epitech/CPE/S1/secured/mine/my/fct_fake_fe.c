/*
** EPITECH PROJECT, 2023
** mini_e
** File description:
** idk
*/

#include "./my.h"

int supplines(double nb, int n)
{
    int part_one = (int)nb;

    n = 1;
    for (; part_one / 10; n++)
        part_one /= 10;
    return (n);
}

int fake_f(double nb)
{
    int a = nb;
    int part_two = 0;
    int n = 0;

    n = supplines(nb, n);
    nb -= a;
    my_put_nbr(a);
    if (n < 6)
        my_putchar('.');
    for (int i = 0; i < 6 - n; i++) {
        nb *= 10;
        part_two = nb;
        my_put_nbr(part_two);
        nb -= part_two;
    }
    return 0;
}

void fake_print_first(int i)
{
    if (i < 10) {
        write(1, "0", 1);
        my_put_nbr(i);
    } else
        my_put_nbr(i);
}

void f_four(double nb)
{
    if (nb >= 1)
        write(1, "e+", 2);
    else
        write(1, "e-", 2);
}

int fake_e(double nb)
{
    int i = 0;

    if (nb == 0) {
        my_putstr("0.000000e+00");
        return (0);
    }
    if (nb > 10) {
        for (; nb > 10; i++)
            nb /= 10;
    } else if (nb < 0) {
        my_putchar('-');
        nb /= -10;
        i++;
    }
    fake_f(nb);
    f_four(nb);
    fake_print_first(i);
    return 0;
}
