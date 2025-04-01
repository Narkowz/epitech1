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

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[j] != '\0' && i < n) {
        if (s1[i] != s2[j])
            return (s1[i] - s2[j]);
        i++;
        j++;
    }
    return (0);
}
