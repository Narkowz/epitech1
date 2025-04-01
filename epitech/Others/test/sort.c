/*
** EPITECH PROJECT, 2023
** sort_by_reverse.c
** File description:
** sort_by_reverse
*/

#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void put_in_list(struct linked_list **list, const char *new_word) 
{
    struct linked_list *new_node = malloc(sizeof(struct linked_list));
    struct linked_list *last;
    new_node->name = strdup(new_word);
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

int open_dir(char **path, int j, int ac)
{
    int i = 0;
    int f = 0;
    DIR *dir;
    struct dirent *entries;
    struct linked_list *list = malloc(sizeof(struct linked_list));

    for (i; i < ac; i++) {
        dir = opendir(path[i]);
        if (dir != NULL) {
            entries = readdir(dir);
            while (entries != NULL) {
                f++;
                put_in_list(&list, entries->d_name);
                entries = readdir(dir);
            }
            print_list(list);
            reverse(list);
        }
        closedir(dir);
    }
    return 0;
}

void reverse(struct linked_list *list)
{
    printf("cc reverse \n");
    struct linked_list *prev = NULL;
    struct linked_list *current = list;
    struct linked_list *next = NULL;

    bubble_sort_bis(current);
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list = prev;
    print_list(list);
}

int sort_by_reverse(char **str, int i, int ac)
{   
    open_dir(str, i, ac);
    return 0;
}