/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

void add_link(linked_t **link, int data)
{
    linked_t *header = *link;
    linked_t *tmp = malloc(sizeof(linked_t));

    tmp->data = data;
    tmp->next = NULL;
    if (header == NULL) {
        *link = tmp;
        return;
    }
    while (header->next != NULL) {
        header = header->next;
    }
    header->next = tmp;
    *link = header;
}

void connect_links(linked_t **link1, linked_t *link2, int index)
{
    linked_t *tmp = *link1;

    while (tmp->next != NULL)
        tmp = tmp->next;
    if (tmp->connected == NULL) {
        tmp->connected = link2;
        return;
    }
    while (tmp->connected->next != NULL)
        tmp->connected = tmp->connected->next;
    tmp->connected = link2;
    *link1 = tmp;
}

void print_my_graph(linked_t *link)
{
    linked_t *tmp = link;
    linked_t *tmp2;

    while (tmp != NULL) {
        while (tmp->connected) {
            printf("%d\n", tmp->connected->data);
            tmp2 = tmp->connected;
            while (tmp2 != NULL) {
                // printf("%d\n", tmp2->data);
                tmp2 = tmp2->next;
            }
            tmp->connected = tmp->connected->next;
        }
        // printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

void print_link(linked_t **link)
{
    while (*link != NULL) {
        printf("%d\n", (*link)->data);
        *link = (*link)->next;
    }   
}

linked_t *build_my_graph(void)
{
    linked_t *link = NULL;
    linked_t *link2 = NULL;
    linked_t *link3 = NULL;
    linked_t *link4 = NULL;

    add_link(&link, 42);
    add_link(&link2, 60012);
    add_link(&link2, 30012);
    // print_link(&link2);
    connect_links(&link, link2, 0);
    // add_link(&link3, 48);
    // add_link(&link3, 50012);
    // add_link(&link3, 3);
    // add_link(&link4, 98);
    // connect_links(&link3, link4, 1);
    // add_link(&link3, 8);
    // connect_links(&link, link3, 1);
    print_my_graph(link);
    return link;
}

int main(int ac, char **av)
{
    linked_t *link = NULL;

    link = build_my_graph();
    print_link(&link);
}
