/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Just put a char
*/

#include "../../include/setting_up.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
