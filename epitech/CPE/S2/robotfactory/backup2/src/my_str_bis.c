/*
** EPITECH PROJECT, 2024
** path_to_array.c
** File description:
** path_to_array
*/

#include "../include/my.h"

char **allocate_array_bis(char *path)
{
    int count = 1;
    char **buf;
    int length = 0;

    for (int k = 0; path[k] != '\0'; k++)
        if ((path[k] == ' ' || path[k] == ',' || path[k] == '\t') && (path[k + 1] != ' ' || path[k + 1] != ',' || path[k + 1] != '\t'))
            count++;
    buf = malloc(sizeof(char *) * (count + 1));
    count = 0;
    for (int k = 0; path[k] != '\0'; k++) {
        if ((path[k] == ' ' || path[k] == ',' || path[k] == '\t') && (path[k + 1] != ' ' || path[k + 1] != ',' || path[k + 1] != '\t')) {
            buf[count] = malloc(sizeof(char) * length + 1);
            count++;
            length = 0;
        } else
            length++;
    }
    buf[count] = malloc(sizeof(char) * length + 1);
    return buf;
}

char **my_str_bis(char *env, char **path)
{
    int i = 0;
    int j = 0;
    int k = 0;

    path = allocate_array_bis(env);
    while (env[i] != '\0') {
        while (env[i] == ' ' || env[i] == '\t' || env[i] == ',')
            i++;
        while (env[i] != '\0' && env[i] != ' ' && env[i] != '\t' && env[i] != ',') {
            path[j][k] = env[i];
            i++;
            k++;
        }
        path[j][k] = '\0';
        j++;
        k = 0;
    }
    path[j][k] = '\0';
    path[j] = NULL;
    return path;
}
