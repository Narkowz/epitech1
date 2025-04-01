/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** concat str
*/

#include "../../include/my.h"

char *hold_null_string(char *str, int n)
{
    char *res = malloc(sizeof(char) * (size_t)(n + 1));
    int i = 0;

    for (i = 0; str[i] && i < n; i++)
        res[i] = str[i];
    res[i] = '\0';
    return res;
}

char *my_strncat(char *s1, char *s2, int n)
{
    char *res = NULL;
    int pos = 0;

    if (!s1 && !s2)
        return NULL;
    if (!s1)
        return hold_null_string(s2, n);
    if (!s2)
        return hold_null_string(s1, n);
    res = malloc(sizeof(char) * (size_t)(my_strlen(s1) + n + 1));
    for (int i = 0; s1[i]; i++) {
        res[pos] = s1[i];
        pos++;
    }
    for (int i = 0; s2[i] && i < n; i++) {
        res[pos] = s2[i];
        pos++;
    }
    res[pos] = '\0';
    return res;
}
