/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** mini printf
*/

#include "../../include/my.h"

int type(char type, va_list args)
{
    char c;

    switch (type) {
    case 'd':
        my_put_nbr(va_arg(args, int));
        break;
    case '%':
        my_putchar('%', 1);
        break;
    case 'c':
        c = va_arg(args, int);
        my_putchar(c, 1);
        break;
    case 'i':
        my_put_nbr(va_arg(args, int));
        break;
    case 's':
        my_putstr(va_arg(args, char *), 1);
        break;
    }
}

int print(char const *str, va_list args)
{
    int i = 0;
    char c;

    for (; str[i] != '\0'; i++) {
        c = str[i];
        if (c == '%') {
            type(str[i + 1], args);
            i++;
        } else {
            my_putchar(c, 1);
        }
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    print(format, args);
    va_end(args);
    return 0;
}
