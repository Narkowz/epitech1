/*
** EPITECH PROJECT, 2023
** bubble_sort.c
** File description:
** bubble_sort
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

void swap_bis(struct linked_list *a, struct linked_list *b)
{
    char *temp = a->name;

    a->name = b->name;
    b->name = temp;
}

void first_if_bis(struct linked_list *ptr, int *swapped)
{
    if (my_strcmp(ptr->name, ptr->next->name) > 0) {
        swap_bis(ptr, ptr->next);
        *swapped = 1;
    } else {
        return;
    }
}

void bubble_sort_bis(struct linked_list *list)
{
    int swapped = 0;
    struct linked_list *ptr;
    struct linked_list *end = NULL;

    if (list == NULL)
        return;
    do {
        swapped = 0;
        ptr = list;
        while (ptr->next != end) {
            first_if_bis(ptr, &swapped);
            ptr = ptr->next;
        }
        end = ptr;
    } while (swapped);
}
