/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** finding_path
*/

#include "main.h"
#include "my.h"

static char *search_path(char **env, char *link_path)
{
    char *copy = strdup(link_path);
    char *result = NULL;

    for (; *env != 0; env++) {
        if (strncmp(*env, copy, strlen(copy)) == 0) {
            result = strdup(*env + strlen(copy));
            free(copy);
            return result;
        }
    }
    return NULL;
}

static char **get_entire_paths(char **paths, char *bin, int nb_paths)
{
    int len_bin;
    int len_path = 0;
    char **full_paths = my_alloc_tab(nb_paths);

    if (bin == NULL)
        return NULL;
    len_bin = (int)strlen(bin);
    for (int index = 0; paths[index] != 0; index++) {
        len_path = (int)strlen(paths[index]);
        full_paths[index] = my_alloc_str(len_path + len_bin + 1);
        full_paths[index] = strcpy(full_paths[index], paths[index]);
        full_paths[index] = strcat(full_paths[index], "/");
        full_paths[index] = strcat(full_paths[index], bin);
    }
    return full_paths;
}

static char **get_paths(char *link_path, char *bin)
{
    char **paths = NULL;
    char *copy = strdup(link_path);
    char *token = NULL;
    int nb_paths = 0;

    token = strtok(copy, ":");
    while (token != NULL) {
        nb_paths++;
        token = strtok(NULL, ":");
    }
    free(copy);
    paths = my_alloc_tab(nb_paths);
    token = strtok(link_path, ":");
    for (int i = 0; token != NULL; i++) {
        paths[i] = strdup(token);
        token = strtok(NULL, ":");
    }
    paths[nb_paths] = 0;
    paths = get_entire_paths(paths, bin, nb_paths);
    return paths;
}

char *get_command(char **env, char *bin)
{
    char *link_path = search_path(env, "PATH=");
    char **paths = get_paths(link_path, bin);

    if (access(bin, F_OK) != -1)
        return bin;
    for (int i = 0; paths && paths[i] != NULL; i++)
        if (access(paths[i], F_OK) != -1)
            return paths[i];
    return NULL;
}
