/*
** EPITECH PROJECT, 2023
** sort_type.c
** File description:
** sort_type
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../shell/shell.h"
#include "../../include/organized.h"

void little_if_type(my_data_t **pivo, my_data_t **changer, int *temp)
{
    int temp_id = (*pivo)->id;
    char *temp_name = my_strdup((*pivo)->name);
    type_t temp_type = (*pivo)->type;

    if ((*pivo)->type > (*changer)->type) {
        (*pivo)->id = (*changer)->id;
        free((*pivo)->name);
        (*pivo)->name = my_strdup((*changer)->name);
        (*pivo)->type = (*changer)->type;
        (*changer)->id = temp_id;
        free((*changer)->name);
        (*changer)->name = my_strdup(temp_name);
        (*changer)->type = temp_type;
        free(temp_name);
    }
}

void quick_sort_type(my_data_t **data, char **args)
{
    my_data_t *pivot = *data;
    my_data_t *changer;
    int temp;

    for (pivot; pivot->next != NULL; pivot = pivot->next) {
        for (changer = pivot->next; changer != NULL; changer = changer->next) {
            little_if_type(&pivot, &changer, &temp);
        }
    }
}
