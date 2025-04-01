/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** print a char
*/

#include "my.h"

int my_putchar(char c, int fd)
{
    write(fd, &c, 1);
    return 1;
}
