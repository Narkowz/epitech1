/*
** EPITECH PROJECT, 2023
** sum_numbers.c
** File description:
** sum numbers
*/

#include <stdarg.h>
#include "./include/my.h"

int sum_numbers(int n, ...)
{
    va_list args;
    int res = 0;
    int i = 0;
    int x = 0;

    va_start(args, n);
    for (; i < n; i++) {
        x = va_arg(args, int);
        res += x;
    }
    va_end(args);
    return res;
}
