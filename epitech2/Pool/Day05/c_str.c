/*
** EPITECH PROJECT, 2025
** c_str.c
** File description:
** c_str
*/

#include <string.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this)
        return NULL;
    return this->str;
}
