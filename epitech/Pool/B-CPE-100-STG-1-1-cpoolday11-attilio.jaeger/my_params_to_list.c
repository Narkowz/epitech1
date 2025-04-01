/*
** EPITECH PROJECT, 2023
** my_params_to_list.c
** File description:
** params to list
*/

#include <stdlib.h>
#include "./include/mylist.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list;
    linked_list_t *next_data;

    list = NULL;
    element = malloc(sizeof(*linked_list_t));
    for (int i = 0; i < ac; i++) {
        element->data = av[i];
        element->next = list;
        list = next_data;
    }
    return (list);
}
