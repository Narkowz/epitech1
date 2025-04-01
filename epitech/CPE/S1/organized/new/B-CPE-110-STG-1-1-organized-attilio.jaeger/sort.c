/*
** EPITECH PROJECT, 2023
** sort.c
** File description:
** sort
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell/shell.h"
#include "include/organized.h"

int is_sort_valid(char *type)
{
    const char *types[] = {
        "ID",
        "NAME",
        "TYPE",
        NULL
    };

    for (int i = 0; types[i] != NULL; i++) {
        if (my_strcmp(types[i], type) == 0)
            return i;
    }
    return -1;
}

int test_arg_sort(char **args)
{
    int i = 0;
    int type = -1;

    for (; args[i] != NULL; i++) {
        type = is_sort_valid(args[i]);
        if (type == -1)
            return 84;
    }
}

int sort(void *data, char **args)
{
    if (!args[0])
        return 84;
    if (test_arg_sort(args) == 84)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "ID") == 0)
            quick_sort_id((my_data_t **)data, args);
        if (my_strcmp(args[i], "NAME") == 0)
            quick_sort_name((my_data_t **)data, args);
        if (my_strcmp(args[i], "TYPE") == 0)
            quick_sort_type((my_data_t **)data, args);
        if (args[1] && my_strcmp(args[i], "-r") == 0)
            reverse((my_data_t **)data);
    }
    return 0;
}
