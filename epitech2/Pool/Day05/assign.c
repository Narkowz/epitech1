/*
** EPITECH PROJECT, 2025
** assign.c
** File description:
** assign
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void assign_c(string_t *this, const char *str)
{
    if (this->str)
        free(this->str);
    if (this)
        this->str = strdup(str);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this->str)
        free(this->str);
    if (this)
        this->str = strdup(str->str);
}
