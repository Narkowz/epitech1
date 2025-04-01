/*
** EPITECH PROJECT, 2024
** test_file.c
** File description:
** test_file
*/

#include "include/my.h"
#include "include/my_navy.h"

int agree_or_not(char *path)
{
    char **pos_path = my_str_to_word_array(path);
    int i = 0;

    for (; i < 3; i++)
        if (pos_path[i][0] != i + '2')
            return 84;
    for (i = 0; i < 3; i++)
        if (pos_path[i][2] > 'H' || pos_path[i][5] > 'H' ||
            pos_path[i][3] > '8' || pos_path[i][6] > '8' ||
            (pos_path[i][2] != pos_path[i][5] &&
            pos_path[i][3] != pos_path[i][6]) || pos_path[i][3] > pos_path[i][6])
            return 84;
    return 0;
}

int test_file(char *path)
{
    int fd;
    char *buf;
    int state;
    int i;

    if (path == NULL)
        return 84;
    fd = open(path, O_RDONLY);
    buf = malloc(sizeof(char) * (31 + 1));
    for (int k = 0; k <= 32; k++)
        buf[k] = '\0';
    if (fd == -1)
        return (84);
    state = read(fd, buf, 32);
    if (buf[0] == '\0')
        return (84);
    close(fd);
    return agree_or_not(buf);
}
