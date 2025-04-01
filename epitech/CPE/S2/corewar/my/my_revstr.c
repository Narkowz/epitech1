/*
** EPITECH PROJECT, 2023
** my strncmp
** File description:
** idk
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "./my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int j = 0;
    char tmp;

    for (int j = 0; i > j; j++) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
    }
    return (str);
}
