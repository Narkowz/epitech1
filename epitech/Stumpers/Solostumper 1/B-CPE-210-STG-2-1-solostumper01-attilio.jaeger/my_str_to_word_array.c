/*
** EPITECH PROJECT, 2024
** opening_file.c
** File description:
** opening_file
*/

#include <sys/stat.h>
#include "include/my.h"

char **allocate_array(char *path)
{
    int count = 1;
    char **buf;

    for (int k = 0; path[k] != '\0'; k++)
        if (path[k] == ' ')
            count++;
    buf = malloc(sizeof(char *) * (count + 1));
    for (int j = 0; j <= count; j++)
        buf[j] = malloc(sizeof(char) * 25);
    return buf;
}

char **my_str_to_word_array(char *path)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **buf = allocate_array(path);

    while (path[i] != '\0') {
        buf[j][k] = path[i];
        if (path[i] == ' ') {
            buf[j][k] = '\0';
            j++;
            k = -1;
        }
        i++;
        k++;
    }
    buf[j][k] = '\0';
    buf[j + 1] = '\0';
    return buf;
}
