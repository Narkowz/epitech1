/*
** EPITECH PROJECT, 2023
** print pointer
** File description:
** print pointer for printf
*/

#include "../../include/my_printf.h"
#include <unistd.h>
#include <stdarg.h>

void pointer_adress(void *ptr)
{
    char hex_chars[] = "0123456789abcdef";
    char hex_buffer[16];
    unsigned long long address = (unsigned long long)ptr;
    int i = 0;
    int num;

    my_putchar('0');
    my_putchar('x');
    if (address == 0) {
        my_putchar('0');
        return;
    }
    while (address > 0) {
        num = address % 16;
        hex_buffer[i] = hex_chars[num];
        address /= 16;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        my_putchar(hex_buffer[j]);
}

void print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);

    pointer_adress(ptr);
}
