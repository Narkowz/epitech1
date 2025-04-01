/*
** EPITECH PROJECT, 2023
** print_hexaup
** File description:
** print hexaup for printf
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

void print_hexanegup(int num, int i)
{
    if (num < 0)
        for (int j = 0; j < i; j++)
            my_putchar('F');
    if (num == 0)
        my_putchar('0');
}

void print_hexadecup(int num)
{
    char numbers[8];
    char charhexa;
    int i = 8;
    unsigned int hexnum = num;
    int lastnum;

    while (hexnum != 0) {
        lastnum = hexnum % 16;
        if (lastnum < 10) {
            charhexa = lastnum + '0';
        } else
            charhexa = (lastnum - 10) + 'A';
        i--;
        numbers[i] = charhexa;
        hexnum /= 16;
    }
    if (num < 0 || num == 0)
        print_hexanegup(num, i);
    for (int j = i; j < 8; j++)
        my_putchar(numbers[j]);
}

void print_hexaup(va_list args)
{
    int num = va_arg(args, int);

    print_hexadecup(num);
}
