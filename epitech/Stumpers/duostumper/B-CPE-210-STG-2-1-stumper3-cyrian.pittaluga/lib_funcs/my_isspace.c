/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_isspace.c
*/

#include "../SRC/include/my_lib.h"

int my_isspace(int c)
{
    return c == ' ' || c == '\t' || c == '\n' ||
    c == '\r' || c == '\f' || c == '\v';
}
