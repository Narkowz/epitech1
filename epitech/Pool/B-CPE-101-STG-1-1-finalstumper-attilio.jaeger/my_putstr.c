/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** print a string
*/

#include "./include/rush3.h"

int my_putstr_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        my_putchar_error(str[i]);
    }
    return (0);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
    }
    return (0);
}
