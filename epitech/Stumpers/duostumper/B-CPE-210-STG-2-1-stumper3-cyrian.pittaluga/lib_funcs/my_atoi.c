/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_atoi.c
*/

#include "../SRC/include/my_lib.h"

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    if (str == NULL) {
        perror("Error: NULL string passed to my_atoi\n");
        return 0;
    }
    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    while (*str && my_isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
