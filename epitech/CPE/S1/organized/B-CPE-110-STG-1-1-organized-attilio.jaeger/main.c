/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell/shell.h"
#include "include/organized.h"

void free_list(my_data_t *data)
{
    my_data_t *current = data;
    my_data_t *next;

    while (current != NULL) {
        free(current->name);
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void)
{
    int returned = 0;
    my_data_t *data = NULL;

    returned = workshop_shell(&data);
    free_list(data);
    return returned;
}
