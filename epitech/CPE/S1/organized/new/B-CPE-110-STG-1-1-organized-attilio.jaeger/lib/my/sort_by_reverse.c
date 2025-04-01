/*
** EPITECH PROJECT, 2023
** sort_by_reverse.c
** File description:
** sort_by_reverse
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../shell/shell.h"
#include "../../include/organized.h"

void reverse(my_data_t **data)
{
    my_data_t *current = *data;
    my_data_t *prev = NULL;
    my_data_t *temp = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    current = prev;
    *data = current;
}
