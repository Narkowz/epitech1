/*
** EPITECH PROJECT, 2023
** add.c
** File description:
** add
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell/shell.h"
#include "include/organized.h"

char *tab_type(type_t type)
{
    switch (type) {
        case ACTUATOR:
            return "ACTUATOR";
        case DEVICE:
            return "DEVICE";
        case WIRE:
            return "WIRE";
        case PROCESSOR:
            return "PROCESSOR";
        case SENSOR:
            return "SENSOR";
    }
}

int test(my_data_t **data, char *args, type_t type)
{
    static int counter = 0;
    my_data_t *new_node = NULL;

    new_node = (my_data_t *) malloc(sizeof(my_data_t));
    new_node->name = my_strdup(args);
    new_node->next = *data;
    new_node->id = counter;
    new_node->type = type;
    *data = new_node;
    mini_printf("%s n°%d - %c%s%c added.\n", tab_type(type), new_node->id,
        34, new_node->name, 34);
    counter++;
    return 0;
}

int is_valid_type(char *type)
{
    const char *types[] = {
        "ACTUATOR",
        "DEVICE",
        "PROCESSOR",
        "SENSOR",
        "WIRE",
        NULL,
    };

    for (int i = 0; types[i] != NULL; i++) {
        if (my_strcmp(types[i], type) == 0)
            return i;
    }
    return -1;
}

int identifier_type(my_data_t **data, char **args)
{
    int i = 0;
    int type = -1;

    for (; args[i] != NULL; i = i + 2) {
        type = is_valid_type(args[i]);
        if (type == -1)
            return 84;
        test((my_data_t **)data, args[i + 1], type);
    }
}

int add(void *data, char **args)
{
    if (!args[0] || !args[1])
        return 84;
    else {
        return identifier_type((my_data_t **)data, args);
    }
}
