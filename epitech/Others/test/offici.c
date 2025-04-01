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
#include "my.h"

struct linked_list *my_put_in_list(struct linked_list *list, char *path)
{
    struct linked_list *element;

    element = malloc(sizeof(element));
    element->name = path;
    element->next = list;
    return element;
}

void my_show_list(struct linked_list *list)
{
    struct linked_list *tmp;

    tmp = list;
    while (tmp != NULL) {
        if (my_strncmp(tmp->name, ".", 1) == 1) {
            tmp = tmp->next;
        }else {
            printf("%s  ", tmp->name);
            tmp = tmp->next;
        }
    }
}

int error_handling(struct dirent *entries, char *path)
{
    DIR *dir = opendir(path);

    if (dir == NULL) {
        printf("No such file or directory\n");
        return 84;
    }
    if (entries == NULL) {
        printf("No such file or directory\n");
        return 84;
    }
    closedir(dir);
    return 0;
}

int my_ls(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entries = readdir(dir);
    struct linked_list *list = NULL;
    struct linked_list *sorted = NULL;

    if (error_handling(entries, path) == 84) {
        printf("Error 404");
    }
    while (entries != NULL) {
        list = my_put_in_list(list, entries->d_name);
        entries = readdir(dir);
    }
    while (&list != NULL) {
        bubble_sort(&list);
        list->next->name;
    }
    my_show_list(&list);
    closedir(dir);
    return (0);
}

int main(int ac, char **av)
{
    my_ls(av[1]);
    return 0;
}
