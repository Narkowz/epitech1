/*
** EPITECH PROJECT, 2025
** empty.c
** File description:
** empty
*/

#include <string.h>
#include "string.h"

int empty(string_t *this)
{
    if (!this || !this->str || strlen(this->str) == 0)
        return 1;
    return 0;
}
