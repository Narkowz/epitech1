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

void whilee(struct linked_list **list, struct dirent *entries, DIR *dir)
{
    while (entries != NULL) {
        put_in_list(list, entries->d_name);
        entries = readdir(dir);
    }
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

static void reverse(struct linked_list *list)
{
    struct linked_list *prev = NULL;
    struct linked_list *current = list;
    struct linked_list *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list = prev;
    print_list(list);
}

static int open_dir_bis(void)
{
    int i = 0;
    DIR *dir;
    struct dirent *entries;
    struct linked_list *list = malloc(sizeof(struct linked_list));

    list = NULL;
    dir = opendir(".");
    if (dir != NULL) {
        entries = readdir(dir);
        while (entries != NULL) {
            put_in_list(&list, entries->d_name);
            entries = readdir(dir);
        }
        bubble_sort_bis(list);
        reverse(list);
    }
    closedir(dir);
    return 0;
}

static int open_dir(char **path, int j, int ac)
{
    int i = 0;
    DIR *dir;
    struct dirent *entries;
    struct linked_list *list = malloc(sizeof(struct linked_list));

    list = NULL;
    for (i; i < ac; i++) {
        dir = opendir(path[i]);
        if (dir != NULL) {
            entries = readdir(dir);
            whilee(&list, entries, dir);
            bubble_sort_bis(list);
            reverse(list);
        }
        closedir(dir);
    }
    return 0;
}

int sort_by_reverse(char **str, int i, int ac)
{
    if (ac <= 2)
        open_dir_bis();
    else
        open_dir(str, i, ac);
    return 0;
}
