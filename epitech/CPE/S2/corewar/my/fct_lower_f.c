/*
** EPITECH PROJECT, 2023
** lower_case_f
** File description:
** main
*/

#include "./my.h"

int lowcase_f(va_list args)
{
    double nb = va_arg(args, double);
    int a = nb;
    int part_two = 0;

    nb -= a;
    my_put_nbr(a);
    my_putchar('.');
    for (int i = 0; i < 6; i++) {
        nb *= 10;
        part_two = nb;
        my_put_nbr(part_two);
        nb -= part_two;
    }
    return (0);
}
