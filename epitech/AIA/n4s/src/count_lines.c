/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** count lines
*/

#include "../include/need4stek.h"

int count_lines(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i++);
    return i;
}
