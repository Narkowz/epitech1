/*
** EPITECH PROJECT, 2024
** binary_to_int.c
** File description:
** binary_to_int
*/

#include "../include/robotfactory.h"

int binary_to_int(char *arg)
{
    int res = 0;

    while (my_strlen(arg) < 8)
        add_word_to_string(arg, "00", &arg, NULL);
    while (*arg != '\0') {
        res = res * 2 + (*arg - '0');
        arg++;
    }
    return res;
}
