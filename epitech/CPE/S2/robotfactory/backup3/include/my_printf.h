/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my printf header
*/

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

typedef void(*format_function)(va_list args);
typedef void (*subflag_function)(va_list, const char *format, int *i);

void my_putchar(char c);
void my_put_nb(int num);
void num_octal(int num);
void my_put_nbr(int num);
void print_a(va_list args);
void print_g(va_list args);
void my_print_a(double num);
void my_print_a(double num);
void print_hexadec(int num);
void print_int(va_list args);
void print_hexa(va_list args);
void print_char(va_list args);
void print_hexadecup(int num);
void print_float(va_list args);
void pointer_adress(void *ptr);
int my_strlen(char const *str);
void print_octal(va_list args);
void print_binary(va_list args);
void my_putstr(char *str);
void print_hexaup(va_list args);
void print_string(va_list args);
void print_percent(va_list args);
void print_floatup(va_list args);
void print_floatvoid(double num);
void print_pointer(va_list args);
void print_unsigned(va_list args);
void print_floatvoidup(double num);
void print_hexaneg(int num, int i);
void print_scientifup(va_list args);
void print_scientific(va_list args);
void print_hexanegup(int num, int i);
void my_put_unsigned(unsigned int num);
int my_printf(const char *format, ...);
void print_e(double num, int i, char sign);
void print_eup(double num, int i, char sign);
void my_putnbr_base(int num, const char *base);
void my_float(int prec, double num, int integer, double dec);
void print_sub_x(va_list args, const char *format, int *i);

#endif /*MY_PRINTF_H*/
