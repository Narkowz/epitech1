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
#include <stdlib.h>

int fs_cat_500_bytes(char const *filepath)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    char *buf;
    int state;

    stat(filepath, &st);
    buf = malloc(sizeof(char) * st.st_size);
    state = read(fd, buf, st.st_size);
    if (fd == -1) {
        printf("open: invalid file or directory\n");
        return 84;
    }
    write(1, buf, 500);
    free(buf);
    close(fd);
}

int main(int ac, char **av)
{
    fs_cat_500_bytes(av[1]);
    return 0;
}
