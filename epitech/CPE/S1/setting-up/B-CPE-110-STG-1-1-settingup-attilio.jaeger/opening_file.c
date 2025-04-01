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
#include "./include/setting_up.h"

char *pass_first_line(char *buf)
{
    int i;

    for (i = 0; buf[i] != '\n'; i++);
    return &buf[i + 1];
}

int count_lines_bis(char *map)
{
    int i = 0;
    int count = 0;

    for (i; map[i] != '\0'; i++)
        if (map[i] == '\n')
            count++;
    return count;
}

int count_cols_bis(char *map)
{
    int cols = 0;

    while (map[cols] != '\n') {
        cols++;
    }
    return cols;
}

int get_nbr_bis(char *av)
{
    int number = 0;
    int i = 0;

    while (av[i] != '\0') {
        number = number * 10 + (av[i] - '0');
        i++;
    }
    return number;
}

static int test_line(char *buf)
{
    int lines = count_lines_bis(buf) - 1;
    int cols = count_cols_bis(buf);
    int veritable_lines;
    int i = 0;
    char *num = malloc(cols * sizeof(char) + 1);

    for (i = 0; buf[i] != '\n'; i++) {
        num[i] = buf[i];
    }
    num[i] = '\0';
    veritable_lines = get_nbr_bis(num);
    if (veritable_lines != lines)
        exit(84);
    return 0;
}

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
    test_line(buf);
    close(fd);
    if (buf[0] != '.' && buf[0] != 'o')
        buf = pass_first_line(buf);
    return buf;
}
