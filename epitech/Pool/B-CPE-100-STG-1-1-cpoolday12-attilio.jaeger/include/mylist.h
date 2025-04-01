/*
** EPITECH PROJECT, 2023
** mylist.h
** File description:
** my list
*/

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
#endif
