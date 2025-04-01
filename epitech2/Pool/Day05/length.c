/*
** EPITECH PROJECT, 2025
** length.c
** File description:
** length
*/

#include <string.h>
#include "string.h"

int length(const string_t *this)
{
    if (!this || !this->str)
        return -1;
    return strlen(this->str);
}
