/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** mini printf
*/

#include <stdarg.h>
#include "../../include/my_radar.h"

int type(char type, va_list args)
{
    char c;

    switch (type) {
    case '%':
        my_putchar('%');
        break;
    case 'c':
        c = va_arg(args, int);
        my_putchar(c);
        break;
    case 's':
        my_putstr(va_arg(args, char *));
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
            my_putchar(c);
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
