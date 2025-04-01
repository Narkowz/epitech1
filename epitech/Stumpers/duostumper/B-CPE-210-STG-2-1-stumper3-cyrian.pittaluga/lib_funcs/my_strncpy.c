/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strncpy.c
*/

#include "../SRC/include/my_lib.h"

void my_strncpy(char *dest, const char *src, int n)
{
    if (src == NULL || dest == NULL) {
        my_puterror("Null pointer input in my_strcpy");
        exit(EXIT_FAILURE);
    }
    while (*src != '\0' && n >= 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
}
