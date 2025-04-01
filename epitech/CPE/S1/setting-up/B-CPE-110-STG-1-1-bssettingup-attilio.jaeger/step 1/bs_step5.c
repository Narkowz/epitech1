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

int fs_print_first_line(char const *filepath)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    char *buf;
    int state;
    int i;

    stat(filepath, &st);
    buf = malloc((sizeof(char) * st.st_size) + 1);
    state = read(fd, buf, st.st_size);
    if (fd == -1) {
        printf("open: invalid file or directory\n");
        return 84;
    }
    for (i = 0; buf[i] != '\n' && buf[i] != '\0'; i++) {
        printf("%c", buf[i]);
    }
    printf("\n");
    free(buf);
    close(fd);
}

int main(int ac, char **av)
{
    fs_print_first_line(av[1]);
    return 0;
}
