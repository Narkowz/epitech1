/*
** EPITECH PROJECT, 2025
** insert.c
** File description:
** insert
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *new_str = NULL;

    if (!this || !this->str || str == NULL)
        return;
    if (pos > strlen(this->str)) {
        append_c(this, str);
        return;
    }
    new_str = malloc(strlen(this->str) + strlen(str) + 1);
    if (new_str != NULL) {
        strncpy(new_str, this->str, pos);
        new_str[pos] = '\0';
        strcat(new_str, str);
        strcat(new_str, this->str + pos);
        free(this->str);
        this->str = new_str;
    }
    return;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (!this || !this->str || !str || !str->str)
        return;
    insert_c(this, pos, str->str);
}
