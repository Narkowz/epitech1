/*
** EPITECH PROJECT, 2023
** upper_case_g
** File description:
** decimal point trailing zero
*/

#include "./my.h"

int uppcase_g(va_list args)
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
    b += 2;
    if (b > 13)
        fake_e_bis(nb);
    else
        fake_f_bis(nb);
    return (0);
}
