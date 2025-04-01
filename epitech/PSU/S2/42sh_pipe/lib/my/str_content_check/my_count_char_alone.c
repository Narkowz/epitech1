/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_count_char_alone.c
*/

#include "my.h"

int my_count_char_alone(char *str, char c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++) {
        if ((str[i] == c && str[i + 1] && str[i + 1] != c) ||
        (str[i] == c && !str[i + 1]))
            count++;
    }
    return count;
}
