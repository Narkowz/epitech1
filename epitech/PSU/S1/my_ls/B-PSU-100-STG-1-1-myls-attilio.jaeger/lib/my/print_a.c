/*
** EPITECH PROJECT, 2023
** print_a.c
** File description:
** print_a
*/

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "../../include/my.h"

void whilee_bis(struct linked_list **list, struct dirent *entries, DIR *dir)
{
    while (entries != NULL) {
        put_in_list(list, entries->d_name);
        entries = readdir(dir);
    }
}

static void put_in_list_a(struct linked_list **list, const char *new_word)
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

void print_a(struct linked_list *list)
{
    struct linked_list *tmp;

    tmp = list;
    while (tmp != NULL) {
        if (tmp->next != NULL) {
            mini_printf("%s  ", tmp->name);
            tmp = tmp->next;
        } else {
            mini_printf("%s\n", tmp->name);
            tmp = NULL;
        }
    }
}

int open_dir_a_bis(void)
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
            put_in_list_a(&list, entries->d_name);
            entries = readdir(dir);
        }
        bubble_sort_bis(list);
        print_a(list);
    }
    closedir(dir);
    return 0;
}

int open_dir_a(char **path, int j, int ac)
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
            whilee_bis(&list, entries, dir);
            bubble_sort_bis(list);
            print_a(list);
        }
        closedir(dir);
    }
    return 0;
}

int print_list_a(char **str, int i, int ac)
{
    if (ac <= 2)
        open_dir_a_bis();
    else
        open_dir_a(str, i, ac);
    return 0;
}
