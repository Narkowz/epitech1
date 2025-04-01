/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_isalpha.c
*/

#include "../SRC/include/my_lib.h"

int my_isalpha(const char *str)
{
    while (*str) {
        if (*str == '-')
            return -1;
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') ||
    (*str >= '0' && *str <= '9') || *str == ' ' || *str == '_')) {
            return -1;
        }
        str++;
    }
    return 0;
}
