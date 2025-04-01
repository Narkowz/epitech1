/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_putchar.c
*/

#include "../SRC/include/my_lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
