/*
** EPITECH PROJECT, 2025
** find.c
** File description:
** find
*/

#include <string.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    const char *start = NULL;

    if (this == NULL || this->str == NULL || str == NULL || pos >=
        strlen(this->str) || strlen(str->str) > strlen(this->str))
        return -1;
    start = strstr(this->str + pos, str->str);
    if (start != NULL)
        return start - this->str;
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    const char *start = NULL;

    if (this == NULL || this->str == NULL || str == NULL ||
        pos >= strlen(this->str))
        return -1;
    start = strstr(this->str + pos, str);
    if (start != NULL)
        return start - this->str;
    return -1;
}
