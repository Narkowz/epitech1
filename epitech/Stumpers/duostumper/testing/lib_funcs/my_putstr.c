/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** my_putstr.c
*/

#include "../SRC/include/my_lib.h"

void my_putstr(char *str)
{
    if (str == NULL) {
        my_puterror("my_putstr; NULL pointer\n");
    } else {
        for (int i = 0; str[i] != '\0'; i++) {
            write(1, &str[i], 1);
        }
    }
}
