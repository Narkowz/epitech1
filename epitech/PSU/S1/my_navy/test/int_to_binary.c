/*
** EPITECH PROJECT, 2024
** int_to_binary.c
** File description:
** int_to_binary
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/my_navy.h"

char *int_to_binary(char arg)
{
    char *binary = malloc(25);
    int i = 0;
    int int_arg = (int) arg;

    while (int_arg > 0) {
        binary[i] = int_arg % 2 + '0';
        int_arg /= 2;
        i++;
    }
    binary[i] = '\0';
    return my_revstr(binary);
}

int binary_to_int(char *arg)
{
    int res = 0;

    while (*arg != '\0') {
        res = res * 2 + (*arg - '0');
        arg++;
    }
    return res;
}
