/*
** EPITECH PROJECT, 2024
** testing_file.c
** File description:
** testing_file
*/

#include "include/my.h"
#include "include/my_navy.h"

int testing_file(char *path)
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
        return (84);
    state = read(fd, buf, st.st_size);
    if (buf[0] == '\0')
        return (84);
    close(fd);
    return 0;
}
