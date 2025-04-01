/*
** EPITECH PROJECT, 2023
** stat.c
** File description:
** stat
*/

#include <sys/types.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/sysmacros.h>

char *name(char **av)
{
    int i = 0;
    int len = my_strlen(av[1]) - 1;
    char *str = malloc(sizeof(char) * (len + 1));

    for (; av[1][len] != '/'; len--) {
        str[i] = av[1][len];
        i++;
    }
    str[i] = '\0';
    return (my_revstr(str));
}

int type(char **av)
{
    struct stat sb;
    printf("Type: ");
    if (S_ISREG(sb.st_mode) == 0) {
        printf("r\n");
    } else if (S_ISDIR(sb.st_mode) != -1) {
        printf("d\n");
    } else if (S_ISLNK(sb.st_mode)!= -1) {
        printf("l\n");
    } else if (S_ISBLK(sb.st_mode)!= -1) {
        printf("b\n");
    } else if (S_ISCHR(sb.st_mode)!= -1) {
        printf("c\n");
    } else if (S_ISFIFO(sb.st_mode)!= -1) {
        printf("p\n");
    } else if (S_ISSOCK(sb.st_mode)!= -1) {
        printf("s\n");
    } else {
        printf("?\n");
    }
    return 0;
}

int main(int ac, char **av)
{
    struct stat *buf;
    buf = malloc(sizeof(struct stat));

    stat(av[1], buf);
    if (stat(av[1], buf) == -1) {
        printf("File not found\n");
        return 84;
    }
    int size = buf->st_size;
    int  uid = buf->st_uid;
    int gid = buf->st_gid;
    int link = buf->st_nlink;
    int inode = buf->st_ino;
    int allocated_space = (buf->st_blocks) * (buf->st_blksize);
    printf("Name: %s\n", name(av));
    type(av);
    printf("Inode: %d\n", inode);
    printf("Size: %d\n", size);
    printf("Allocated space: %d\n", allocated_space);
    printf("Minor: \n");
    printf("Major: \n");
    printf("Hard link: %d\n", link);
    printf("UID: %d\n", uid);
    printf("GID: %d\n", gid);
    free(buf);
    return 0;
}
