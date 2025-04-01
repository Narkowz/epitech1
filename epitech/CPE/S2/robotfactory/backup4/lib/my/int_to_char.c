/*
** EPITECH PROJECT, 2023
** int_to_char.c
** File description:
** int_to_char
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/my.h"

int count_length(int value)
{
    int i = 0;

    for (; value > 0; i++)
        value /= 10;
    return i;
}

char *char_to_int(char *value)
{
    int i = 0;

    for (; value[i] != '\0'; i++)
        value[i] = value[i] - '0';
    return value;
}

char *if_one(int value, char **buffer)
{
    if (value == 1) {
        *buffer = malloc(sizeof(char) * 3);
        (*buffer)[0] = '0';
        (*buffer)[1] = '1';
        (*buffer)[2] = '\0';
        return *buffer;
    }
    return NULL;
}

char *int_to_char(int value)
{
    int i = 0;
    int num = value;
    char *buffer = NULL;
    int len = 0;

    if (if_one(value, &buffer) == NULL) {
        while (num != 0) {
            num /= 10;
            len++;
        }
        buffer = malloc(sizeof(char) * (len + 1));
        for (int j = len - 1; j >= 0; --j) {
            buffer[i + j] = '0' + (value % 10);
            value /= 10;
        }
        buffer[i + len] = '\0';
    }
    return buffer;
}
