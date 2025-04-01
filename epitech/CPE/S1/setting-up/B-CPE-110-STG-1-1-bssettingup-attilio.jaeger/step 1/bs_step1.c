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

int fs_open_file(char const *filepath)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    char buf[st.st_size];
    int state;

    if (fd == -1) {
        printf("open: invalid file or directory\n");
        return 84;
    }
    state = read(fd, buf, st.st_size);
    if (state != -1) {
        printf("SUCCESS\n");
        return 0;
    } else {
        printf("FAILURE\n");
        return 84;
    }
    close(fd);
}
