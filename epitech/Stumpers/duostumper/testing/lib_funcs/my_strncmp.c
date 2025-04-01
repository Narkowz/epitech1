/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strncmp.c
*/

#include "../SRC/include/my_lib.h"

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    if (str1 == NULL || str2 == NULL)
        return -1;
    for (size_t i = 0; i < n && str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
    }
    return 0;
}
