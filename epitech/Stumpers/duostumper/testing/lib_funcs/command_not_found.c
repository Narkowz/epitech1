/*
** EPITECH PROJECT, 2024
** Project_Template
** File description:
** command_not_found.c
*/

#include "../SRC/include/my_lib.h"

void command_not_found(char *str)
{
    if (str[0] == 'n') {
        my_putstr("\\n");
    } else {
        my_puterror(str);
    }
    my_puterror(": Command not found.\n");
}
