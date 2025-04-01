/*
** EPITECH PROJECT, 2023
** step1.c
** File description:
** step1
*/

#include <unistd.h>
#include "organized.h"

typedef struct linked_list {
    char *node;
    struct linked_list *next;
}linked_list_t;

void push_to_list(linked_list_t **begin, void *data)
{
    begin->node = strdup((char *)data);
    begin->next = NULL;
    if (begin == NULL)
}

void put_in_list(struct linked_list **list, const char *new_word)
{
    struct linked_list *new_node = malloc(sizeof(struct linked_list));
    struct linked_list *last;

    new_node->name = my_strdup(new_word);
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    last = *list;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int main(int argc, char **argv)
{

    return 0;
}