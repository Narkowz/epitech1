/*
** EPITECH PROJECT, 2023
** cat.c
** File description:
** cat
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/my/my.h"

int read_files(int argc, char **argv)
{
    int fd;
    char buffer[30000];
    int temp;

    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
            return (84);
        temp = read(fd, buffer, 30000);
        buffer[temp] = '\0';
        my_putstr(buffer);
    }
    close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    char buffer[30000];

    if (argc == 1) {
        fd = read(0, buffer, 30000);
        while (fd > 0) {
            buffer[fd] = '\0';
            my_putstr(buffer);
            fd = read(0, buffer, 30000);
        }
    } else
        return (read_files(argc, argv));
    return (0);
}
