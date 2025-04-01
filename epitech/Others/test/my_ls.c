/*
** EPITECH PROJECT, 2023
** my_ls.c
** File description:
** my_ls
*/

#include <sys/types.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <string.h>
#include "my.h"

int my_ls(char *path)
{
    DIR *dir = opendir(path);
    struct linked_list *list;

    if (dir == NULL) {
        printf("No such file or directory\n");
        return 84;
    }
    struct dirent *entries = readdir(dir);
    if (entries == NULL) {
        printf("No such file or directory\n");
        return 84;
    }
    while (entries != NULL) {
        if (my_strncmp(entries->d_name, ".", 1) == 1) {
            entries = readdir(dir);
            continue;
        }
        printf("%s ", entries->d_name);
        entries = readdir(dir);
    }
    closedir(dir);
    return (0);
}

int main(int ac, char **av)
{
    my_ls(av[1]);
    return 0;
}
