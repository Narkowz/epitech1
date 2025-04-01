/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** mini printf
*/

#include <stdarg.h>
//#include "./include/my.h"

static void digits(va_list args)
{
    my_put_nbr(va_arg(args, int));
}

static void single_char(va_list args)
{
    char c;

    c = va_arg(args, int);
    my_putchar(c);
}

static void intergrers(va_list args)
{
    my_put_nbr(va_arg(args, int));
}

static void print_string(va_list args)
{
    my_putstr(va_arg(args, char *));
}

static void print_percentage(va_list args)
{
    my_putchar('%');
}

/*static void for_spaces(char flag, char str, int i, int j)
{
    for (j = 0; flag[j] != '\0'; j++) {
        if (flag[j] == str[i + 1]) {
            ptr2func[j](args);
        }
    }
}*/

static int my_strnlen(char const *str, int n)
{
    int i = 0;

    while (str[i] != '\0' && i < n)
        i++;
    return (i);
}

int print(char const *str, va_list args)
{
    int i = 0;
    char c;
    int j = 0;
    char flag[6] = "dcis%n";
    int (*ptr2func[6])(va_list) = {&digits, &single_char
        , &intergrers, &print_string, &print_percentage
        , &my_strnlen};

    for (; str[i] != '\0' ; i++) {
        c = str[i];
        if (c == '%') {
            for (j = 0; flag[j] != '\0'; j++) {
                if (flag[j] == str[i + 1]) {
                    ptr2func[j](args);
                    }
            }
            i++;
        } else {
            my_putchar(c);
        }
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    print(format, args);
    va_end(args);
    return 0;
}

int main(void)
{
    char e = 'a';
    mini_printf("bonjour %d, %c %i %s %% %n", 5, e, 15, "salut");
    return 0;
}
