/*
** EPITECH PROJECT, 2023
** disp_stdarg.c
** File description:
** disp std arg
*/

#include <stdarg.h>
#include "../include/my.h"

void disp_stdarg(char *s, ...)
{
    va_list args;
    va_start(args, n);
    int res = 0;
    int i = 0;

    for (; i < n; i++) {
        char x = va_arg(args, int);
        my_putchar(x);
    }
    va_end(args);
    return 0;
}

int main(int argc, char * argv)
{
    
    return 0;
}
