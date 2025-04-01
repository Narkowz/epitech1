/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_strcpy.c
*/

#include "../SRC/include/my_lib.h"

void my_strcpy(char *dest, const char *src)
{
    if (src == NULL || dest == NULL) {
        my_puterror("Null pointer input in my_strcpy");
        exit(EXIT_FAILURE);
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
