/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Just put a char
*/

#include "../../include/my_radar.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
