/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int len;
    int i = 0;

    len = my_strlen(dest);
    while (src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
