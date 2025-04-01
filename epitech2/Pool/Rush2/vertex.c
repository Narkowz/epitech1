/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Vertex class implementation
*/

#include "vertex.h"
#include "object.h"
#include "raise.h"
#include "new.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct vertex_s {
    Class base;
    int x;
    int y;
    int z;
} vertex_t;

static void Vertex_ctor(Object *self, va_list *ap)
{
    vertex_t *vertex = (vertex_t *)self;

    if (!ap)
        raise("Invalid argument list for Vertex");
    vertex->x = va_arg(*ap, int);
    vertex->y = va_arg(*ap, int);
    vertex->z = va_arg(*ap, int);
}

static void Vertex_dtor(Object *self)
{
    (void)self;
}

static char *Vertex_str(Object *self)
{
    vertex_t *vertex = (vertex_t *)self;
    size_t size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", vertex->x, vertex->y, vertex->z) + 1;
    char *str = malloc(size);

    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size, "<Vertex (%d, %d, %d)>", vertex->x, vertex->y, vertex->z);
    return str;
}

static Object *Vertex_add(const Object *self, const Object *other)
{
    const vertex_t *v1 = (const vertex_t *)self;
    const vertex_t *v2 = (const vertex_t *)other;

    return new(Vertex, v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

static Object *Vertex_sub(const Object *self, const Object *other)
{
    const vertex_t *v1 = (const vertex_t *)self;
    const vertex_t *v2 = (const vertex_t *)other;

    return new(Vertex, v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

static bool Vertex_eq(const Object *self, const Object *other)
{
    const vertex_t *v1 = (const vertex_t *)self;
    const vertex_t *v2 = (const vertex_t *)other;

    return (v1->x == v2->x) && (v1->y == v2->y) && (v1->z == v2->z);
}

static bool Vertex_lt(const Object *self, const Object *other)
{
    const vertex_t *v1 = (const vertex_t *)self;
    const vertex_t *v2 = (const vertex_t *)other;

    return (v1->x < v2->x) || (v1->x == v2->x && v1->y < v2->y) || 
           (v1->x == v2->x && v1->y == v2->y && v1->z < v2->z);
}

static bool Vertex_gt(const Object *self, const Object *other)
{
    const vertex_t *v1 = (const vertex_t *)self;
    const vertex_t *v2 = (const vertex_t *)other;

    return (v1->x > v2->x) || (v1->x == v2->x && v1->y > v2->y) || 
           (v1->x == v2->x && v1->y == v2->y && v1->z > v2->z);
}

static const vertex_t _description = {
    {
        sizeof(vertex_t),
        "Vertex",
        &Vertex_ctor,
        &Vertex_dtor,
        &Vertex_str,
        &Vertex_add,
        &Vertex_sub,
        NULL,
        NULL,
        &Vertex_eq,
        &Vertex_lt,
        &Vertex_gt
    },
    0, 0, 0
};

const Class *Vertex = (const Class *)&_description;
