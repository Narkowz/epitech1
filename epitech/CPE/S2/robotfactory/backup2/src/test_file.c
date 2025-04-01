/*
** EPITECH PROJECT, 2024
** test_file.c
** File description:
** test_file
*/

#include "../include/robotfactory.h"

int clean_line(char *cont)
{
    int i = 0;

    while (cont[i] == '\t' || cont[i] == ' ')
        i++;
    return i;
}

int open_file(char *path, char **content)
{
    int readed;
    int fd = open(path, 'r');
    char *buffer = NULL;
    struct stat sa;

    stat(path, &sa);
    buffer = malloc(sa.st_size + 1);
    readed = read(fd, buffer, sa.st_size);
    buffer[readed] = '\0';
    close(fd);
    *content = my_strdup(buffer);
    free(buffer);
    return 0;
}

static int test_name(char **array)
{
    int len = my_strlen(".name");
    int count = -1;
    int counter = 0;
    int i = 0;

    for (; array[i] != NULL; i++)
        if (my_strncmp(".name", array[i], len, clean_line(array[i])) == len) {
            count = i;
            break;
        }
    if (count == -1)
        return 84;
    for (int i = 0; array[count][i] != '\0'; i++)
        if (array[count][i] == '"')
            counter++;
    if (counter != 2)
        return 84;
    return 0;
}

static int test_comment(char **array)
{
    int len = my_strlen(".comment");
    int count = -1;
    int counter = 0;
    int i = 0;

    for (; array[i] != NULL; i++)
        if (my_strncmp(".comment", array[i], len, clean_line(array[i])) == len)
            break;
    if (i == count_line(array))
        return 0;
    for (int l = 0; array[i][l] != '\0'; l++)
        if (array[i][l] == '"')
            counter++;
    if (counter != 2)
        return 84;
    return 0;
}

int test_content(char **array)
{
    if (test_name(array) != 0)
        return 84;
    if (test_comment(array) != 0)
        return 84;
    return 0;
}

int test_file(char *file)
{
    int len = my_strlen(file) - 1;
    char *cont = NULL;
    struct stat sa;

    if (file[len] != 's' || file[len - 1] != '.')
        return 84;
    if (stat(file, &sa) != 0)
        return 84;
    return 0;
}
