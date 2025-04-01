/*
** EPITECH PROJECT, 2023
** lower_case_u
** File description:
** usigned decimal integer
*/

#include "./my.h"

int lowcase_u(va_list args)
{
    long nb = va_arg(args, long);

    lowcase_u_bis(nb);
    return 0;
}

int lowcase_u_bis(long nb)
{
    char temp;

    if (nb < 0)
        nb = nb + 4294967295;
    if (nb <= 4294967296 && nb >= 0) {
        if (nb / 10 != 0)
            lowcase_u_bis(nb / 10);
        temp = '0' + (nb % 10);
        write(1, &temp, 1);
    }
    return 0;
}

int lowcase_o(va_list args)
{
    long nb = va_arg(args, long);

    lowcase_o_bis(nb);
    return 0;
}

int lowcase_o_bis(long nb)
{
    char temp;

    if (nb < 0)
        return 84;
    if (nb <= 4294967296 && nb >= 0) {
        if (nb / 8 != 0)
            lowcase_o_bis(nb / 8);
        temp = '0' + (nb % 8);
        write(1, &temp, 1);
    }
    return 0;
}
