/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_puterror.c
*/

#include "../SRC/include/my_lib.h"

void my_puterror(char *str)
{
    if (str == NULL) {
        my_puterror("My_puterror() was called with a NULL string.");
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
}
