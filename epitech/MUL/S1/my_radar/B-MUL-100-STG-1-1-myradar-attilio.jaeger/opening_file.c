/*
** EPITECH PROJECT, 2024
** opening_file.c
** File description:
** opening_file
*/

#include <sys/stat.h>
#include "include/my_radar.h"

int allowed_file(char *path)
{
    int i = 0;
    int len = my_strlen(path) - 4;
    char testing[5];
    int state = -1;

    if (len < 0)
        return 84;
    for (; path[len] != '\0'; len++) {
        testing[i] = path[len];
        i++;
    }
    testing[i] = '\0';
    state = my_strcmp(testing, ".rdr");
    return state;
}

char **allocate_array(char *path)
{
    int count = 1;
    char **buf;

    for (int k = 0; path[k] != '\0'; k++)
        if (path[k] == ' ' || path[k] == '\n')
            count++;
    buf = malloc(sizeof(char *) * (count + 1));
    for (int j = 0; j <= count; j++)
        buf[j] = malloc(sizeof(char) * 25);
    return buf;
}

char **my_str_to_word_array(char *path)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **buf = allocate_array(path);

    while (path[i] != '\0') {
        buf[j][k] = path[i];
        if (path[i] == '\n') {
            buf[j][k] = '\0';
            j++;
            k = -1;
        }
        i++;
        k++;
    }
    buf[j][k] = '\0';
    buf[j + 1] = '\0';
    return buf;
}

char **opening_file(char *path)
{
    struct stat st;
    int fd = open(path, O_RDONLY);
    char *buf;
    char **res = NULL;
    int state;
    int i;

    stat(path, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    for (int k = 0; k <= st.st_size; k++)
        buf[k] = '\0';
    state = read(fd, buf, st.st_size);
    close(fd);
    res = my_str_to_word_array(buf);
    return res;
}
