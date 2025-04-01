/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** printf
*/

#include "./my.h"

int lowcase_s(va_list args)
{
    my_putstr(va_arg(args, char *));
    return 0;
}

int lowcase_c(va_list args)
{
    my_putchar(va_arg(args, int));
    return 0;
}

int lowcase_i(va_list args)
{
    my_put_nbr(va_arg(args, int));
    return 0;
}

int lowcase_d(va_list args)
{
    my_put_nbr(va_arg(args, int));
    return 0;
}

int low_percent(va_list args)
{
    my_putchar('%');
    return 0;
}
