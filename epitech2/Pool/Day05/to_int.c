/*
** EPITECH PROJECT, 2025
** to_int.c
** File description:
** to_int
*/

#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    if (!this || !this->str)
        return 0;
    return atoi(this->str);
}
