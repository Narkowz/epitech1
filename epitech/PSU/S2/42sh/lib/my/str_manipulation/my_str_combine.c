/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** my_add_char.c
*/

#include "my.h"

char *my_str_combine(char *str, char *str2)
{
    int len = (my_strlen(str) + my_strlen(str2));
    char *end_str = my_alloc_str(len + 2);
    int index = 0;

    for (int i = 0; str[i]; i++) {
        end_str[i] = str[i];
        index++;
    }
    if (str[index] != '/') {
        end_str[index] = '/';
        index++;
    }
    for (int i = 0; str2[i]; i++) {
        end_str[index] = str2[i];
        index++;
    }
    return end_str;
}
