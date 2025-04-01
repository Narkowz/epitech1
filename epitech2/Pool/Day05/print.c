/*
** EPITECH PROJECT, 2025
** print.c
** File description:
** print
*/

#include <stdio.h>
#include "string.h"

void print(const string_t *this)
{
    if (this && this->str)
        printf("%s", this->str);
}
