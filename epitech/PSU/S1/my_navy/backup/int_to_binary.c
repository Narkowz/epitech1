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

int *int_to_binarys(int arg)
{
    int *binary = malloc(5);
    int i = 0;
    int int_arg = arg;

    while (int_arg > 0) {
        binary[i] = int_arg % 2;
        int_arg /= 2;
        i++;
    }
    if ((i - 1) % 4 != 0) {
        i++;
        binary[i] = 0;
    }
    binary[i + 1] = -1;
    return binary;
}

void int_to_binary(char *msg)
{
    int *res = int_to_binarys(msg[0] - 64);
    int i = 0;

    for (; res[i] != -1; i++);
    for (int k = i - 1; k >= 0; k--)
        printf("test %d\n", res[k]);   
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
