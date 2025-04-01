/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Int class implementation
*/

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "list.h"
#include "new.h"
#include "raise.h"

typedef struct list_node_s {
    Object *data;
    struct list_node_s *next;
    struct list_node_s *prev;
} list_node_t;

typedef struct list_class_s {
    Container base;
    list_node_t *head;
    list_node_t *tail;
    size_t size;
} list_class_t;

static void list_add_back(list_class_t *self, Object *data)
{
    list_node_t *node = malloc(sizeof(list_node_t));
    node->data = data;
    node->next = NULL;
    node->prev = self->tail;

    if (!node)
        raise("Out of memory");
    if (self->tail)
        self->tail->next = node;
    else
        self->head = node;
    self->tail = node;
    self->size++;
}

static void list_destroy(Object *self)
{
    list_class_t *list = NULL;
    list_node_t *current = NULL;
    list_node_t *next = NULL;

    list = (list_class_t *)self;
    current = list->head;
    while (current) {
        next = current->next;
        if (current->data) {
            delete(current->data);
            current->data = NULL;
        }
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

static size_t list_len(Container *self)
{
    return ((list_class_t *)self)->size;
}

static void list_setitem(Container *self, ...)
{
    list_class_t *list = (list_class_t *)self;
    va_list args;
    Object *data;

    va_start(args, self);
    data = va_arg(args, Object *);
    va_end(args);
    list_add_back(list, data);
}

static Object *list_getitem(Container *self, ...)
{
    list_class_t *list = (list_class_t *)self;
    va_list args;
    size_t index;
    list_node_t *current;

    va_start(args, self);
    index = va_arg(args, size_t);
    va_end(args);
    if (index >= list->size) {
        fprintf(stderr, "Error: Index %zu out of range (size: %zu)\n", index, list->size);
        return NULL;
    }
    current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

static const list_class_t _description = {
    {
        {
            sizeof(list_class_t),
            "List",
            NULL,
            &list_destroy,
        },
        &list_len,
        NULL,
        NULL,
        &list_getitem,
        &list_setitem,
    },
    NULL,
    NULL,
    0
};

const Class *List = (const Class *)&_description;
