/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Float class implementation
*/

#include "float.h"
#include "object.h"
#include "new.h"
#include "raise.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    Class base;
    float value;
} FloatClass;

static void Float_ctor(Object *self, va_list *ap)
{
    FloatClass *f = (FloatClass *)self;

    f->value = (float)va_arg(*ap, double);
}

static void Float_dtor(Object *self)
{
    (void*)self;
}

static char *Float_str(Object *self)
{
    FloatClass *f = (FloatClass *)self;
    size_t size = snprintf(NULL, 0, "<Float (%.2f)>", f->value) + 1;
    char *str = malloc(size);

    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size, "<Float (%.2f)>", f->value);
    return str;
}

static Object *Float_add(const Object *self, const Object *other)
{
    FloatClass *f1 = (FloatClass *)self;
    FloatClass *f2 = (FloatClass *)other;

    return new(Float, f1->value + f2->value);
}

static Object *Float_sub(const Object *self, const Object *other)
{
    FloatClass *f1 = (FloatClass *)self;
    FloatClass *f2 = (FloatClass *)other;

    return new(Float, f1->value - f2->value);
}

static Object *Float_mul(const Object *self, const Object *other)
{
    FloatClass *f1 = (FloatClass *)self;
    FloatClass *f2 = (FloatClass *)other;

    return new(Float, f1->value * f2->value);
}

static Object *Float_div(const Object *self, const Object *other)
{
    FloatClass *f1 = (FloatClass *)self;
    FloatClass *f2 = (FloatClass *)other;

    if (f2->value == 0.0)
        raise("Division by zero");
    return new(Float, f1->value / f2->value);
}

static bool Float_eq(const Object *self, const Object *other)
{
    FloatClass *f1 = (FloatClass *)self;
    FloatClass *f2 = (FloatClass *)other;

    return (f1->value == f2->value);
}

static bool Float_lt(const Object *self, const Object *other)
{
    FloatClass *f1 = (FloatClass *)self;
    FloatClass *f2 = (FloatClass *)other;

    return (f1->value < f2->value);
}

static bool Float_gt(const Object *self, const Object *other)
{
    FloatClass *f1 = (FloatClass *)self;
    FloatClass *f2 = (FloatClass *)other;

    return (f1->value > f2->value);
}

static const FloatClass _description = {
    {
        sizeof(FloatClass),
        "Float",
        Float_ctor,
        Float_dtor,
        Float_str,
        Float_add,
        Float_sub,
        Float_mul,
        Float_div,
        Float_eq,
        Float_lt,
        Float_gt},
    0.0
};

const Class *Float = (const Class *)&_description;
