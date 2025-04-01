/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** printf 
*/

#include <stdarg.h>

void print_unsigned(void)
{
    int num = 5;
    int i = 0;
    int res = 0;
    if (num < 0) {
        do {
            res = my_compute_power_rec(2, i);
            i++;
        } while (i <= 32);
    }
    res = res + num;
    my_put_nbr(res);
}

void main(void)
{
    print_unsigned();
}
