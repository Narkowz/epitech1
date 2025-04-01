/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-bsminishell1-titouan.pradoura
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char const *str, int fd)
{
    if (str)
        write(fd, str, (size_t)my_strlen(str));
    return 0;
}
