/*
** EPITECH PROJECT, 2023
** error_handling.c
** File description:
** error_handling
*/

#include <dirent.h>
#include <stdio.h>
#include "../../include/my.h"

int error_handling(char *path)
{
    DIR *dir;

    if (path[0] == '-') {
        return (0);
    } else {
        dir = opendir(path);
        if (dir == NULL) {
            mini_printf("ls: cannot access '%s': ", path);
            mini_printf("No such file or directory\n");
            return 84;
        }
        closedir(dir);
    }
    return 0;
}
