/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** printf
*/

#include "./my.h"

const struct Flag format_bis[] = {
    {'e', &lowcase_e},
    {'f', &lowcase_f},
    {'u', &lowcase_u},
    {'o', &lowcase_o},
    {'E', &uppcase_e},
    {'F', &uppcase_f},
    {'s', &lowcase_s},
    {'c', &lowcase_c},
    {'i', &lowcase_i},
    {'d', &lowcase_d},
    {'%', &low_percent},
    {'x', &lowcase_x},
    {'X', &uppcase_x},
    {'g', &lowcase_g},
    {'G', &uppcase_g},
    {'p', &lowcase_p},

    {'\0', NULL}
};

void my_format(const char format, va_list args)
{
    for (int i = 0; format_bis[i].format != '\0'; i++) {
        if (format_bis[i].format == format)
            format_bis[i].fonction(args);
    }
}

int my_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            my_format(format[i + 1], args);
            i++;
        } else
            my_putchar(format[i]);
    }
    va_end(args);
    return (0);
}
