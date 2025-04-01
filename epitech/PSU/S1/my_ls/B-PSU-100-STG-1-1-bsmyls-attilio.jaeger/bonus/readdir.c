/*
** EPITECH PROJECT, 2023
** readdir.c
** File description:
** readdir
*/

#include <stdlib.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <stdio.h>

int main(int ac, char **av)
{
    DIR *dir = opendir(av[1]);

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
        printf("%s\n", entries->d_name);
        entries = readdir(dir);
    }
    closedir(dir);
    return 0;
}
