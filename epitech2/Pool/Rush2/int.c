/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Int class implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "int.h"
#include "new.h"
#include "object.h"
#include "raise.h"

typedef struct int_s {
    Class base;
    int value;
} int_t;

static void Int_ctor(Object *self, va_list *ap)
{
    int_t *i = (int_t *)self;

    if (!ap)
        raise("Invalid argument list for Int");
    i->value = va_arg(*ap, int);
}

static void Int_dtor(Object *self)
{
    (void)self;
}

static Object *Int_add(const Object *self, const Object *other)
{
    const int_t *i1 = (const int_t *)self;
    const int_t *i2 = (const int_t *)other;

    return new(Int, i1->value + i2->value);
}

static Object *Int_sub(const Object *self, const Object *other)
{
    const int_t *i1 = (const int_t *)self;
    const int_t *i2 = (const int_t *)other;

    return new(Int, i1->value - i2->value);
}

static Object *Int_mul(const Object *self, const Object *other)
{
    const int_t *i1 = (const int_t *)self;
    const int_t *i2 = (const int_t *)other;

    return new(Int, i1->value * i2->value);
}

static Object *Int_div(const Object *self, const Object *other)
{
    const int_t *i1 = (const int_t *)self;
    const int_t *i2 = (const int_t *)other;

    if (i2->value == 0)
        raise("Division by zero");
    return new(Int, i1->value / i2->value);
}

static bool Int_eq(const Object *self, const Object *other)
{
    const int_t *i1 = (const int_t *)self;
    const int_t *i2 = (const int_t *)other;

    return (i1->value == i2->value);
}

static bool Int_lt(const Object *self, const Object *other)
{
    const int_t *i1 = (const int_t *)self;
    const int_t *i2 = (const int_t *)other;

    return (i1->value < i2->value);
}

static bool Int_gt(const Object *self, const Object *other)
{
    const int_t *i1 = (const int_t *)self;
    const int_t *i2 = (const int_t *)other;

    return (i1->value > i2->value);
}

static char *Int_str(Object *self)
{
    int_t *i = (int_t *)self;
    size_t size = snprintf(NULL, 0, "<Int (%d)>", i->value) + 1;
    char *str = malloc(size);

    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size, "<Int (%d)>", i->value);
    return str;
}

static const int_t _description = {
    {
        .__size__ = sizeof(int_t),
        .__name__ = "Int",
        .__ctor__ = Int_ctor,
        .__dtor__ = Int_dtor,
        .__str__ = Int_str,
        .__add__ = Int_add,
        .__sub__ = Int_sub,
        .__mul__ = Int_mul,
        .__div__ = Int_div,
        .__eq__ = Int_eq,
        .__lt__ = Int_lt,
        .__gt__ = Int_gt
    },
    .value = 0
};

const Class *Int = (const Class *)&_description;
