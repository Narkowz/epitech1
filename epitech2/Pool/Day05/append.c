/*
** EPITECH PROJECT, 2025
** appen.c
** File description:
** append
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *new_str = NULL;

    if (!this || !ap || !this->str || !ap->str)
        return;
    new_str = malloc(strlen(this->str) + strlen(ap->str) + 1);
    if (new_str != NULL) {
        new_str[0] = '\0';
        strcat(new_str, this->str);
        strcat(new_str, ap->str);
        free(this->str);
        this->str = new_str;
    }
    return;
}

void append_c(string_t *this, const char *ap)
{
    char *new_str = NULL;

    if (!this || !ap || !this->str)
        return;
    new_str = malloc(strlen(this->str) + strlen(ap) + 1);
    if (new_str != NULL) {
        new_str[0] = '\0';
        strcat(new_str, this->str);
        strcat(new_str, ap);
        free(this->str);
        this->str = new_str;
    }
    return;
}
