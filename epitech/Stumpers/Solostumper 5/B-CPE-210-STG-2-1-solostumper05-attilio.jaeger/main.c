/*
** EPITECH PROJECT, 2024
** luhn_validator.c
** File description:
** luhn validator
*/

#include "include/my.h"
#include <stdio.h>

void operator(int *result, int *doubled)
{
    if (*doubled > 9)
        *result += *doubled - 9;
    else
        *result += *doubled;
}

int validator(char *str)
{
    int len = my_strlen(str) - 1;
    int i = 1;
    int result = (int)str[len] - 48;
    int doubled = 0;

    for (; i <= len; i++) {
        if (i % 2 == 1) {
            doubled = ((int)str[len - i] - 48) * 2;
            operator(&result, &doubled);
        } else
            result += (int)str[len - i] - 48;
    }
    return result % 10;
}

int test_input(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (test_input(av[1]) == 1)
        return 84;
    if (validator(av[1]) == 0) {
        write(1, "valid", 5);
        write(1, "\n", 1);
    } else {
        write(1, "invalid", 7);
        write(1, "\n", 1);
    }
    return 0;
}
