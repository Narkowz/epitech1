/*
** EPITECH PROJECT, 2023
** lower_case_g
** File description:
** decimal point trailing zero
*/

#include "./my.h"

int lowcase_g(va_list args)
{
    double a = va_arg(args, double);
    double nb = a;
    int part_one = (int)nb;
    int part_two = (int)((nb - part_one) * 1000000);
    int b = 8;

    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    for (int i = 10; part_one / i; b++)
        part_one /= i;
    for (int i = 10; part_two / i; b++)
        part_two /= i;
    if (b > 13)
        fake_e(nb);
    else
        fake_f(nb);
    return (0);
}
