/*
** EPITECH PROJECT, 2023
** disp.c
** File description:
** disp
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell/shell.h"
#include "include/organized.h"

void disp_list(my_data_t **data, char **args)
{
    my_data_t *current = *data;

    while (current != NULL) {
        mini_printf("%s n°%d - %c%s%c\n", tab_type(current->type),
            current->id, 34, current->name, 34);
        current = current->next;
    }
}

int disp(void *data, char **args)
{
    disp_list((my_data_t **)data, args);
    return 0;
}
