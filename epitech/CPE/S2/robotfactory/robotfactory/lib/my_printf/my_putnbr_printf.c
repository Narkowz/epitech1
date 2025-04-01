/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** put nbr
*/

#include "../../include/my_printf.h"

void my_put_nbr(int num)
{
    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num >= 10) {
        my_put_nbr(num / 10);
    }
    my_putchar('0' + num % 10);
}

void my_putnbr_base(int num, const char *base)
{
    int base_len = my_strlen(base);

    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num >= base_len) {
        my_putnbr_base(num / base_len, base);
    }
    my_putchar(base[num % base_len]);
}
