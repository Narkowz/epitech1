/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_cut_at_first_occur.c
*/

#include "my.h"

char *cut_at_char(char *str, char c)
{
    int cut = my_locate_char(str, c);
    char *temp;

    if (cut == -1)
        return str;
    temp = my_str_slice(str, 0, cut - 1);
    return temp;
}
