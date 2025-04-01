/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** concat str
*/

#include "my.h"

char *my_strcat(char *s1, char *s2)
{
    char *res = my_alloc_str(my_strlen(s1) + my_strlen(s2));
    int pos = 0;

    for (int i = 0; s1[i]; i++) {
        res[pos] = s1[i];
        pos++;
    }
    for (int i = 0; s2[i]; i++) {
        res[pos] = s2[i];
        pos++;
    }
    return res;
}
