/*
** EPITECH PROJECT, 2024
** find_paladrome.c
** File description:
** find_paladrome
*/

#include "include/my.h"
#include <stdio.h>

int find_palindrome(char *str)
{
    char *reversed;

    if (my_strlen(str) == 0)
        return 84;
    reversed = my_strdup(str);
    reversed = my_revstr(reversed);
    if (my_strcmp(reversed, str) == 0)
        my_putstr("palindrome!\n");
    else
        my_putstr("not a palindrome.\n");
    return 0;
}
