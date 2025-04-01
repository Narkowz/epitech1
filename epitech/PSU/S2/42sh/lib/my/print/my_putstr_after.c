/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** my_putstr_after.c
*/

#include "my.h"

void my_putstr_after(char *str, int n, int fd)
{
    int iter = 0;

    if (!str || n >= my_strlen(str))
        return;
    for (int i = n; str[i]; i++) {
        write(fd, &str[i], 1);
        iter++;
    }
    for (int i = 0; i < iter; i++) {
        dprintf(1, "\x1b[D");
    }
}
