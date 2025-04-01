/*
** EPITECH PROJECT, 2023
** int_to_char.c
** File description:
** int_to_char
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/my.h"

char *int_to_char(int value)
{
    int i = 0;
    int num = value;
    char *buffer;
    int len = 0;

    while (num != 0) {
        num /= 10;
        len++;
    }
    buffer = malloc(sizeof(len));
    for (int j = len - 1; j >= 0; --j) {
        buffer[i + j] = '0' + (value % 10);
        value /= 10;
    }
    buffer[i + len] = '\0';
    return buffer;
}

char *add_to_string(char *buffer, char *adding)
{
    int len = strlen(adding);
    int len2 = strlen(buffer);
    int i;
    char *result = malloc(sizeof(buffer) + len);

    result = buffer;
    for (i = 0; i < len; i++) {
        result[len2 + i - len] = adding[i];
    }
    result[len2 + i + len] = '\0';
    return result;
}
