/*
** EPITECH PROJECT, 2023
** print g
** File description:
** print %g for printf
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void print_g(va_list args)
{
    double value = va_arg(args, double);

    if (value == 0.0) {
        my_printf("%f", value);
    } else if (value < 1e-4 || value >= 1e6) {
        my_printf("%e", value);
    } else {
        my_printf("%f", value);
    }
}
