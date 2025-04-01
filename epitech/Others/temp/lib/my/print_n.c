/*
** EPITECH PROJECT, 2023
** print_n.c
** File description:
** print n
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_n(va_list args)
{
    int *count = va_arg(args, int *);
    *count = write(1, "", 0);
}
