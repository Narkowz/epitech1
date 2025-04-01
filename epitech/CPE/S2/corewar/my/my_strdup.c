/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** my_strdup
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "./my.h"

char *my_strdup(const char *s)
{
    char *copy = malloc(my_strlen(s) + 1);

    if (copy)
        my_strcpy(copy, s);
    return copy;
}
