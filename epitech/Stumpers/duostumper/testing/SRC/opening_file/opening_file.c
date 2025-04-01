/*
** EPITECH PROJECT, 2023
** opening_file.c
** File description:
** opening_file
*/

#include "../include/game_of_life.h"
#include "../include/my_lib.h"

void test_exist(char *buf, int fd)
{
    if (fd == -1) {
        if (buf != NULL)
            free(buf);
        exit(84);
    }
}

void test_empty(char *buf)
{
    if (buf[0] == '\0') {
        if (buf != NULL)
            free(buf);
        exit(84);
    }
}

char *opening_file(char *path)
{
    struct stat st;
    int fd = open(path, O_RDONLY);
    char *buf = NULL;
    int state;
    int i;

    test_exist(buf, fd);
    stat(path, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    for (int k = 0; k <= st.st_size; k++)
        buf[k] = '\0';
    state = read(fd, buf, st.st_size);
    test_empty(buf);
    if (buf[my_strlen(buf) - 1] == '\n')
        buf[my_strlen(buf) - 1] = '\0';
    close(fd);
    return buf;
}
