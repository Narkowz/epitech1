/*
** EPITECH PROJECT, 2023
** mini E
** File description:
** idk
*/

#include "./my.h"

void print_first_bis(int i)
{
    if (i < 10) {
        write(1, "0", 1);
        my_put_nbr(i);
    } else
        my_put_nbr(i);
}

int print_e_bis(int nb)
{
    if (nb > 0)
        write(1, "E+", 2);
    else
        write(1, "E-", 2);
    return (0);
}

int uppcase_e(va_list args)
{
    double nb = va_arg(args, double);
    int i = 0;

    if (nb == 0) {
        my_putstr("0.000000E+00");
        return (0);
    }
    if (nb >= 10) {
        for (; nb >= 10; i++)
            nb /= 10;
    } else if (nb < 0) {
        my_putchar('-');
        nb /= -10;
        i++;
    }
    my_printf("%f", nb);
    print_e_bis(nb);
    print_first_bis(i);
    return 0;
}
