/*
** EPITECH PROJECT, 2023
** upper_case_x
** File description:
** usigned decimal integer
*/

#include "./my.h"

int fct_switch_bis(long a)
{
    char temp_bis;

    if (a < 10)
        temp_bis = '0' + a;
    else
        temp_bis = 'A' + (a - 10);
    write(1, &temp_bis, 1);
    return 0;
}

int uppcase_x_bis(long a)
{
    char temp;

    if (a) {
        uppcase_x_bis(a / 16);
        fct_switch_bis(a % 16);
    }
    return 0;
}

int uppcase_x(va_list args)
{
    long a = va_arg(args, long);

    if (a < 0)
        return 84;
    if (a == 0) {
        write(1, "0", 1);
        return 0;
    } else
        uppcase_x_bis(a);
    return 0;
}
