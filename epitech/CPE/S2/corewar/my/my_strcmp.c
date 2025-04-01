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

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int s1len = strlen(s1);
    int s2len = strlen(s2);

    if (s1len != s2len)
        return 1;
    for (; i < s1len; i++) {
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}
