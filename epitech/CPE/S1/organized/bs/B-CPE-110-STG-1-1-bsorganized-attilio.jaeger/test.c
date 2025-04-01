/*
** EPITECH PROJECT, 2023
** step1.c
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Linked list library/organized.h"

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(84);
    }

    new_node->data = strdup(data);
    new_node->next = NULL;

    if (*begin == NULL) {
        *begin = new_node;
        return;
    }

    linked_list_t *last = *begin;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

static void display_int(void *data)
{
    printf("%d\n", *(int *)data);
}

void display_list(linked_list_t *begin, void (*disp_fct)(void *data))
{
    linked_list_t *current = begin;
    while (current != NULL) {
        disp_fct(current->data);
        current = current->next;
    }
}

static int compare_in_list(void const *ref, void *data)
{
    return (*(int *)ref - *(int *)data);
}

void delete_in_list(linked_list_t **begin, const void *ref, int (*cmp_fct)(void const *ref, void *data))
{
    linked_list_t *current = *begin;
    linked_list_t *prev = NULL;

    while (current != NULL) {
        if (cmp_fct(&ref, current->data) == 0) {
            if (prev == NULL) {
                *begin = current->next;
            } else {
                prev->next = current->next;
            }
        }
        prev = current;
        current = current->next;
    }
}

int main(int argc, char **argv)
{
    linked_list_t *myList = NULL;
    int word1 = 12;
    int word2 = 25;
    int word3 = 75;
    int word4 = 8;
    int test = 8;
    int nb = 3;
    int try = 8;

    push_to_list(&myList, &word1);
    push_to_list(&myList, &word2);
    push_to_list(&myList, &word3);
    push_to_list(&myList, &word4);
    push_to_list(&myList, &nb);
    push_to_list(&myList, &test);
    display_list(myList, &display_int);
    delete_in_list(&myList, try, &compare_in_list);
    display_list(myList, &display_int);
    linked_list_t *current = myList;
    current = myList;
    while (current != NULL) {
        linked_list_t *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    return 0;
}
