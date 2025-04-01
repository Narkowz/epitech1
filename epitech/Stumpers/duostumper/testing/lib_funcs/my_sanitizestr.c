/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_sanitizestr.c
*/

#include "../SRC/include/my_lib.h"

static void add_space_if_needed(char *clean_str, int *j,
    int *is_last_char_space)
{
    if (!*is_last_char_space) {
        clean_str[*j] = ' ';
        (*j)++;
        *is_last_char_space = 1;
    }
}

static void add_char(char *clean_str, char dirty_char, int *j,
    int *is_last_char_space)
{
    clean_str[*j] = dirty_char;
    (*j)++;
    *is_last_char_space = 0;
}

char *my_sanitizestr(char *dirty_str)
{
    char *clean_str;
    int is_last_char_space = 0;
    int j = 0;

    if (!dirty_str)
        return NULL;
    clean_str = (char *)malloc(my_strlen(dirty_str) + 1);
    if (!clean_str)
        return NULL;
    for (int i = 0; dirty_str[i] != '\0'; i++) {
        if (dirty_str[i] == ' ' || dirty_str[i] == '\t') {
            add_space_if_needed(clean_str, &j, &is_last_char_space);
        } else {
            add_char(clean_str, dirty_str[i], &j, &is_last_char_space);
        }
    }
    clean_str[j] = '\0';
    return clean_str;
}
