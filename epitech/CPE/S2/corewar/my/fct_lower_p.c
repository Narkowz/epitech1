/*
** EPITECH PROJECT, 2023
** lower_p
** File description:
** pointer adress
*/

#include "./my.h"

int lowcase_p(va_list args)
{
    long nb = va_arg(args, long);

    my_printf("0x%x", nb);
    return (0);
}
