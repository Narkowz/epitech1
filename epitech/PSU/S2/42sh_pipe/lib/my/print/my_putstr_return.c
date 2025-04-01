/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-titouan.pradoura
** File description:
** my_putstr_return.c
*/

#include "my.h"

int my_putstr_return(char *str, int fd, int val)
{
    if (str)
        write(fd, str, (size_t)my_strlen(str));
    return val;
}
