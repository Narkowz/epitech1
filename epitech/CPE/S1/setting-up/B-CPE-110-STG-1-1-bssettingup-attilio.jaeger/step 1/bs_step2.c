/*
** EPITECH PROJECT, 2023
** bs_step1.c
** File description:
** bs_step1
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int state = read(fd, buffer, size);

    if (fd == -1) {
        printf("open: invalid file or directory\n");
        return 84;
    }
    fs_error_handling(state, size);
}

int fs_error_handling(int state, int size)
{
    struct stat st;

    if (state == -1) {
        printf("read failed\n");
        return state;
    }
    if (state == 0) {
        printf("read has nothing more to read\n");
        return state;
    }
    if (state < size) {
        printf("read didn't complete the entire buffer\n");
        return state;
    }
    if (state == size) {
        printf("read complete the entire buffer\n");
        return state;
    }
}
