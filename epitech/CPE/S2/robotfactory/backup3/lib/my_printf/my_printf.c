/*
** EPITECH PROJECT, 2023
** MINI_PRINTF
** File description:
** Mini printf
*/

#include "../../include/my_printf.h"
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

struct format_specifier {
    char specifier;
    format_function func;
    struct subflag *subflags_list;
};

struct format_specifier format_flag[] = {
    {'a', print_a},
    {'g', print_g},
    {'i', print_int},
    {'d', print_int},
    {'x', print_hexa},
    {'c', print_char},
    {'f', print_float},
    {'F', print_floatup},
    {'%', print_percent},
    {'b', print_binary},
    {'o', print_octal},
    {'s', print_string},
    {'X', print_hexaup},
    {'p', print_pointer},
    {'e', print_scientific},
    {'E', print_scientifup},
    {'u', print_unsigned},
};

struct subflag {
    char subflag_char;
    subflag_function subfunc;
};

struct subflag subflags[] = {
    {'#', print_sub_x},
};

static void process(const char *format, int *i, va_list args)
{
    size_t j = 0;
    int temp = *i;

    for (; j < sizeof(format_flag) / sizeof(format_flag[0]); j++) {
        if (*format == format_flag[j].specifier) {
            format_flag[j].func(args);
            return;
        }
        if (*format == subflags[j].subflag_char) {
            subflags[j].subfunc(args, format, i);
            temp++;
            *i = temp;
            process(format + 1, i, args);
            return;
        }
    }
    my_putchar(*format);
}

static void check_percent(const char *format, int *i, va_list args)
{
    int j = *i;

    if (format[j]) {
        if (format[j] == ' ')
            process(format + j, &j, args);
        process(format + j, &j, args);
    } else
        return;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%') {
            i++;
            check_percent(format, &i, args);
        } else
            my_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (0);
}
