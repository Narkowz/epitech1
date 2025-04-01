/*
** EPITECH PROJECT, 2024
** start_program.c
** File description:
** start_program
*/

#include <unistd.h>
#include "include/my.h"

char print_lower_case(char path)
{
    if (path >= 'A' && path <= 'Z')
        return path + 32;
    else
        return path;
}

char print_upper_case(char path)
{
    if (path >= 'a' && path <= 'z')
        return path - 32;
    else
        return path;
}

int start_program(char *path)
{
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == 'o' || path[i] == 'O')
            path[i] = '0';
        if (path[i] == 'i' || path[i] == 'I')
            path[i] = '1';
        if (path[i] == 'u' || path[i] == 'U')
            path[i] = '2';
        if (path[i] == 'e' || path[i] == 'E')
            path[i] = '3';
        if (path[i] == 'a' || path[i] == 'A')
            path[i] = '4';
        if (path[i] == 'y' || path[i] == 'Y')
            path[i] = '5';
        if (i % 2 == 0)
            path[i] = print_upper_case(path[i]);
        else
            path[i] = print_lower_case(path[i]);
    }
    write(1, path, my_strlen(path));
    write(1, "\n", 1);
}
