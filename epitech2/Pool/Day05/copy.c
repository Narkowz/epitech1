/*
** EPITECH PROJECT, 2025
** copy.c
** File description:
** copy
*/

#include <string.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t length = 0;

    if (!this || !this->str || !s || pos >= strlen(this->str))
        return 0;
    length = strlen(this->str) - pos + 1;
    length = (length < n ? length : n);
    for (size_t i = 0; i < length; i++)
        s[i] = this->str[pos + i];
    return length;
}
