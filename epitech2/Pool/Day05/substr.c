/*
** EPITECH PROJECT, 2025
** substr.c
** File description:
** substr
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

static string_t *create_string(const char *str, int length)
{
    string_t *new_str = malloc(sizeof(string_t));

    if (!new_str)
        return NULL;
    new_str->str = malloc((length + 1) * sizeof(char));
    if (!new_str->str) {
        free(new_str);
        return NULL;
    }
    strncpy(new_str->str, str, length);
    new_str->str[length] = '\0';
    return new_str;
}

string_t *substr(const string_t *this, int offset, int length)
{
    int str_len = 0;

    if (!this || !this->str)
        return NULL;
    str_len = strlen(this->str);
    if (offset < 0)
        offset = str_len + offset;
    if (length < 0)
        length = offset + length;
    if (offset < 0)
        offset = 0;
    if (length < 0)
        length = 0;
    if (offset >= str_len)
        return create_string("", 0);
    if (offset + length > str_len)
        length = str_len - offset;
    return create_string(this->str + offset, length);
}
