/*
** EPITECH PROJECT, 2023
** dell.c
** File description:
** del
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell/shell.h"
#include "include/organized.h"

static int compare_int(int args, int id)
{
    return (id - args);
}

void del_if(
    my_data_t **current, my_data_t *prev, char *args, my_data_t **data)
{
    if (prev == NULL) {
        *data = (*current)->next;
        free(*current);
    } else {
        prev->next = (*current)->next;
        free(*current);
    }
}

void del_fun(
    my_data_t **current, my_data_t *prev, char *args, my_data_t **data)
{
    while (*current != NULL) {
        if (compare_int(get_nbr(args), (*current)->id) == 0) {
            mini_printf("%s n°%d - %c%s%c deleted.\n",
            tab_type((*current)->type), (*current)->id, 34,
            (*current)->name, 34);
            del_if(current, prev, args, data);
        }
        if ((*current)->next == NULL)
            break;
        prev = *current;
        *current = (*current)->next;
    }
}

int del(void *data, char **args)
{
    my_data_t *current = *(my_data_t **)data;
    my_data_t *prev = NULL;
    int i = 0;

    if (!args[0])
        return 84;
    for (; args[i] != NULL; i++) {
        del_fun(&current, prev, args[i], (my_data_t **)data);
        current = *(my_data_t **)data;
        prev = NULL;
    }
    return 0;
}
