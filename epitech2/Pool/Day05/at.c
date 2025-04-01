/*
** EPITECH PROJECT, 2025
** at.c
** File description:
** at
*/

#include <string.h>
#include "string.h"

char string_at(const string_t *this, size_t pos)
{
    if (!this || !this->str || strlen(this->str) <= pos)
        return -1;
    return this->str[pos];
}
