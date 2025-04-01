/*
** EPITECH PROJECT, 2024
** path_to_array.c
** File description:
** path_to_array
*/

#include "include/need4stek.h"
#include <stdio.h>
#include <stdlib.h>

char **allocate_array_str(char *path)
{
    int count = 1;
    char **buf;
    int length = 0;

    for (int k = 0; path[k] != '\0'; k++)
        if (path[k] == ':')
            count++;
    buf = malloc(sizeof(char *) * (count + 1));
    count = 0;
    for (int k = 0; path[k] != '\0'; k++) {
        if (path[k] == ':') {
            buf[count] = malloc(sizeof(char) * length + 1);
            count++;
            length = 0;
        } else
            length++;
    }
    buf[count] = malloc(sizeof(char) * length + 1);
    return buf;
}

char **my_str_to_word_array(char *env, char **path)
{
    int i = 0;
    int j = 0;
    int k = 0;

    path = allocate_array_str(env);
    while (env[i] != '\0') {
        path[j][k] = env[i];
        if (env[i] == ':') {
            path[j][k] = '\0';
            j++;
            k = -1;
        }
        i++;
        k++;
    }
    path[j][k] = '\0';
    path[j + 1] = NULL;
    return path;
}
