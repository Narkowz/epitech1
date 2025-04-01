/*
** EPITECH PROJECT, 2023
** opening_file.c
** File description:
** opening_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/cesar.h"

char *opening_file(char *path)
{
    struct stat st;
    int fd = open(path, O_RDONLY);
    char *buf;
    int state;
    int i;

    stat(path, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    for (int k = 0; k <= st.st_size; k++)
        buf[k] = '\0';
    if (fd == -1)
        exit(84);
    state = read(fd, buf, st.st_size);
    if (buf[0] == '\0')
        exit(84);
    close(fd);
    return buf;
}
