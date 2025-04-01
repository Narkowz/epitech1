/*
** EPITECH PROJECT, 2024
** add_to_file.c
** File description:
** add_to_file
*/

#include "../include/robotfactory.h"

char *just_malloc(char *name, int len, int i, int *k)
{
    for (; len - i != 0; i++)
        if (name[len - i] != '/')
            *k++;
        else
            break;
}

char *get_path(char *name)
{
    int len = my_strlen(name) - 3;
    int i = 0;
    int k = 0;
    char *path = NULL;

    just_malloc(name, len, i, &k);
    path = malloc(sizeof(char) * (k + 2));
    k = 0;
    for (i = 0; len - i != -1; i++) {
        if (name[len - i] != '/') {
            path[k] = name[len - i];
            k++;
        } else
            break;
    }
    path[k] = '\0';
    return my_revstr(path);
}

void add_to_file(header_t *content, char *name, robot_t *robot)
{
    FILE *file;

    name = get_path(name);
    add_word_to_string(name, ".cor", &name, NULL);
    file = fopen(name, "w+");
    robot->file = file;
    fwrite(content, sizeof(header_t), 1, file);
}
