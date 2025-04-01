/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-titouan.pradoura
** File description:
** is_alpha_score.c
*/

#include "my.h"

int is_alpha_score(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' ||
    (c >= '0' && c <= '9')) {
        return 1;
    } else {
        return 0;
    }
}
