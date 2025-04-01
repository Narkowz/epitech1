/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Just put a char
*/

#include "./include/rush3.h"

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
