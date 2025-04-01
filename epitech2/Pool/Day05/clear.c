/*
** EPITECH PROJECT, 2025
** clear.c
** File description:
** clear
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void clear(string_t *this)
{
    if (!this || !this->str)
        return;
    free(this->str);
    this->str = NULL;
}
