/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Just put a char
*/

#include "../../include/my.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}
