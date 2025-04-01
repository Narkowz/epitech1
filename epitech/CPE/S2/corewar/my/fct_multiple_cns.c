/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** printf
*/

#include "./my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    long n;
    char temp;

    n = nb;
    if (n < 0) {
        n *= -1;
        write(1, "-", 1);
    }
    if (n) {
        if (n / 10)
            my_put_nbr(n / 10);
        temp = 48 + (n % 10);
        write(1, &temp, 1);
    }
    if (n == 0)
        write(1, "0", 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
