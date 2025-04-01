/*
** EPITECH PROJECT, 2023
** lower_case_x
** File description:
** usigned decimal integer
*/

#include "./my.h"

int fct_switch(long a)
{
    char temp_bis;

    if (a < 10)
        temp_bis = '0' + a;
    else
        temp_bis = 'a' + (a - 10);
    write(1, &temp_bis, 1);
    return 0;
}

int lowcase_x_bis(long a)
{
    char temp;

    if (a) {
        lowcase_x_bis(a / 16);
        fct_switch(a % 16);
    }
    return 0;
}

int lowcase_x(va_list args)
{
    long a = va_arg(args, long);

    if (a < 0)
        return 84;
    if (a == 0) {
        write(1, "0", 1);
        return 0;
    } else
        lowcase_x_bis(a);
    return 0;
}
