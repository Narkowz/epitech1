/*
** EPITECH PROJECT, 2025
** string_init.c
** File description:
** string_init
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void string_init_bis(string_t **this)
{
    (*this)->copy = copy;
    (*this)->c_str = c_str;
    (*this)->empty = empty;
    (*this)->find_s = find_s;
    (*this)->find_c = find_c;
    (*this)->insert_c = insert_c;
    (*this)->split_c = split_c;
    (*this)->split_s = split_s;
    (*this)->print = print;
    (*this)->join_c = join_c;
    (*this)->join_s = join_s;
    (*this)->substr = substr;
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_c = assign_c;
    this->assign_s = assign_s;
    this->append_s = append_s;
    this->append_c = append_c;
    this->at = string_at;
    this->clear = clear;
    this->length = length;
    this->compare_c = compare_c;
    this->compare_s = compare_s;
    string_init_bis(&this);
}

void string_destroy(string_t *this)
{
    if (this != NULL && this->str != NULL) {
        free(this->str);
        this->str = NULL;
    }
}
