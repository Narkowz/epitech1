/*
** EPITECH PROJECT, 2023
** my_ls.c
** File description:
** my_ls
*/

#include <sys/types.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include "../../include/my.h"

void my_put_in_list(struct linked_list **list, char *path)
{
    struct linked_list *element = malloc(sizeof(struct linked_list));

    element->name = my_strdup(path);
    element->next = *list;
    *list = element;
}

void my_show_list(struct linked_list *list)
{
    struct linked_list *tmp;

    tmp = list;
    while (tmp != NULL) {
        if (tmp->next == NULL) {
            mini_printf("%s\n", tmp->name);
            break;
        }
        if (my_strncmp(tmp->name, ".", 1) == 1) {
            tmp = tmp->next;
        } else {
            mini_printf("%s  ", tmp->name);
            tmp = tmp->next;
        }
    }
}

void free_list(struct linked_list *list)
{
    struct linked_list *current = list;
    struct linked_list *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
}

int my_simple_ls(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entries = readdir(dir);
    struct linked_list *list = NULL;

    while (entries != NULL) {
        my_put_in_list(&list, entries->d_name);
        entries = readdir(dir);
    }
    bubble_sort(list);
    my_show_list(list);
    closedir(dir);
    free_list(list);
    return (0);
}
