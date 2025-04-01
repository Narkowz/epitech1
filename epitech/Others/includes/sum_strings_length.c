/*
** EPITECH PROJECT, 2023
** sum_strings_length.c
** File description:
** sum strings length
*/

#include <stdarg.h>
#include "./include/my.h"

int sum_strings_length(int n, ...)
{
    va_list args;
    int len = 0;
    int i = 0;
    int res = 0;

    va_start(args, n);
    for (;i < n; i++) {
        len = my_strlen(va_arg(args, char *));
        res += len;
    }
    va_end(args);
    return (res);
}
