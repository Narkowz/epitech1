/*
** EPITECH PROJECT, 2023
** print_list.c
** File description:
** print_list
*/

#include <stdio.h>
#include "../../include/my.h"

void print_list(struct linked_list *list)
{
    struct linked_list *tmp;

    tmp = list;
    while (tmp != NULL) {
        if (tmp->next == NULL) {
            mini_printf("%s\n", tmp->name);
            tmp = tmp->next;
            continue;
        }
        if (my_strncmp(tmp->name, ".", 1) == 1) {
            tmp = tmp->next;
            continue;
        } else {
            mini_printf("%s  ", tmp->name);
            tmp = tmp->next;
            continue;
        }
    }
}
