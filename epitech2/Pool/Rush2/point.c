/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Point class implementation
*/

#include "point.h"
#include "object.h"
#include "raise.h"
#include "new.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct point_s {
    Class base;
    int x;
    int y;
} point_t;

static void Point_ctor(Object *self, va_list *ap)
{
    point_t *point = (point_t *)self;

    if (!ap)
        raise("Invalid argument list for Point");
    point->x = va_arg(*ap, int);
    point->y = va_arg(*ap, int);
}

static void Point_dtor(Object *self)
{
    (void)self;
}

static char *Point_str(Object *self)
{
    point_t *point = (point_t *)self;
    size_t size = snprintf(NULL, 0, "<Point (%d, %d)>", point->x, point->y) + 1;
    char *str = malloc(size);

    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size, "<Point (%d, %d)>", point->x, point->y);
    return str;
}

static Object *Point_add(const Object *self, const Object *other)
{
    const point_t *p1 = (const point_t *)self;
    const point_t *p2 = (const point_t *)other;

    return new(Point, p1->x + p2->x, p1->y + p2->y);
}

static Object *Point_sub(const Object *self, const Object *other)
{
    const point_t *p1 = (const point_t *)self;
    const point_t *p2 = (const point_t *)other;

    return new(Point, p1->x - p2->x, p1->y - p2->y);
}

static bool Point_eq(const Object *self, const Object *other)
{
    const point_t *p1 = (const point_t *)self;
    const point_t *p2 = (const point_t *)other;

    return (p1->x == p2->x) && (p1->y == p2->y);
}

static bool Point_lt(const Object *self, const Object *other)
{
    const point_t *p1 = (const point_t *)self;
    const point_t *p2 = (const point_t *)other;

    if (p1->x < p2->x)
        return true;
    if (p1->x == p2->x && p1->y < p2->y)
        return true;
    return false;
}

static bool Point_gt(const Object *self, const Object *other)
{
    return !Point_lt(self, other) && !Point_eq(self, other);
}

static const point_t _description = {
    {
        sizeof(point_t),
        "Point",
        &Point_ctor,
        &Point_dtor,
        &Point_str,
        &Point_add,
        &Point_sub,
        NULL,
        NULL,
        &Point_eq,
        &Point_lt,
        &Point_gt
    },
    0, 0
};

const Class *Point = (const Class *)&_description;
