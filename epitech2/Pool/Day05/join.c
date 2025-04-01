/*
** EPITECH PROJECT, 2025
** join.c
** File description:
** join
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

static int total_length(const char *const *array, char delim)
{
    int total_len = 0;
    int i = 0;

    while (array[i] != NULL) {
        total_len += strlen(array[i]);
        if (array[i + 1] != NULL)
            total_len++;
        i++;
    }
    return total_len;
}

static int allocate_memory(string_t *this, int total_len)
{
    this->str = malloc((total_len + 1) * sizeof(char));
    if (!this->str)
        return 0;
    return 1;
}

static void copy_strings(string_t *this, const char *const *array, char delim)
{
    int i = 0;
    int pos = 0;
    int len = 0;

    while (array[i] != NULL) {
        len = strlen(array[i]);
        memcpy(&this->str[pos], array[i], len);
        pos += len;
        if (array[i + 1] != NULL) {
            this->str[pos] = delim;
            pos++;
        }
        i++;
    }
    this->str[pos] = '\0';
}

void join_c(string_t *this, char delim, const char *const *array)
{
    int total_len = 0;

    if (!this || !array)
        return;
    total_len = total_length(array, delim);
    if (!allocate_memory(this, total_len))
        return;
    copy_strings(this, array, delim);
}

static int count_string_t(const string_t *const *array)
{
    int count = 0;

    while (array[count] != NULL) {
        count++;
    }
    return count;
}

void join_s(string_t *this, char delim, const string_t *const *array)
{
    int i = 0;
    const char **c_array = NULL;

    if (!this || !array) {
        return;
    }
    c_array = malloc((count_string_t(array) + 1) * sizeof(char *));
    if (!c_array)
        return;
    while (array[i] != NULL) {
        c_array[i] = array[i]->str;
        i++;
    }
    c_array[i] = NULL;
    join_c(this, delim, c_array);
    free(c_array);
}

void free_string(string_t *this)
{
    if (this && this->str) {
        free(this->str);
        this->str = NULL;
    }
}
