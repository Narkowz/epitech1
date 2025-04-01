/*
** EPITECH PROJECT, 2025
** mul_div.c Ex01
** File description:
** Ex 01 of Day04am of the pool Tech2
*/

#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    (*mul) = a * b;
    if (b != 0)
        (*div) = a / b;
    else
        (*div) = 42;
}

void mul_div_short(int *a, int *b)
{
    int x = (*a);
    int y = (*b);

    (*a) = x * y;
    if (*b != 0)
        (*b) = x / y;
    else
        (*b) = 42;
}

// static void test_short ( void )
// {
//     int a = 12;
//     int b = 0;
//     int mul_res = a;
//     int div_res = b;

//     mul_div_short (&mul_res, &div_res) ;
//     printf ("%d * %d = %d\n", a, b, mul_res);
//     printf ("%d / %d = %d\n", a, b, div_res) ;
// }

// void test_long(void)
// {
//     int a = 13;
//     int b = 0;
//     int mul;
//     int div;

//     mul_div_long(a, b, &mul, &div);
//     printf("%d * %d = %d\n", a, b, mul);
//     printf("%d / %d = %d\n", a, b, div);
// }

// int main(void)
// {
//     test_long();
//     test_short();
//     return 0;
// }
