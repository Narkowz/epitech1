/*
** EPITECH PROJECT, 2023
** print a
** File description:
** print %a
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

static void convert_significand(char *output, double significand)
{
    int num;
    int i = 0;

    while (significand != 0 && i < 20) {
        num = (int)significand;
        output[i] = (num < 10) ? ('0' + num) : ('a' + num - 10);
        significand = (significand - num) * 16.0;
        i++;
    }
    output[i] = '\0';
}

static void fill_exponent(char *output, int exp, int exp_digits, int i)
{
    for (int j = i + exp_digits - 1; j >= i; j--) {
        output[j] = '0' + exp % 10;
        exp /= 10;
    }
}

void print_output(char *output, double num, int exp, char sign)
{
    int i = 0;
    int exp_abs;
    int exp_digits;

    while (output[i] != '\0') {
        i++;
    }
    output[i++] = 'p';
    output[i++] = sign;
    exp_abs = (exp < 0) ? -exp : exp;
    if (exp_abs < 10)
        exp_digits = 1;
    else if (exp_abs < 100)
        exp_digits = 2;
    else
        exp_digits = 3;
    fill_exponent(output, exp_abs, exp_digits, i);
    i += exp_digits;
    output[i] = '\0';
}

static void convert_sign_and_exp(char *output, double num)
{
    int exp = 0;
    double significand = num;
    char sign = (significand < 0) ? '-' : '+';

    significand = (significand < 0) ? -significand : significand;
    while (significand >= 2.0) {
        significand /= 2.0;
        exp++;
    }
    while (significand < 1.0) {
        significand *= 2.0;
        exp--;
    }
    convert_significand(output, significand);
    print_output(output, num, exp, sign);
}

void my_print_a(double num)
{
    char output[64];

    convert_sign_and_exp(output, num);
    output[0] = '.';
    my_printf("0x1%s", output);
}

void print_a(va_list args)
{
    double num = va_arg(args, double);

    my_print_a(num);
}
