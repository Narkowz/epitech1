/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Char class implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "char.h"
#include "new.h"
#include "raise.h"

typedef struct char_class_s {
    Class base;
    char value;
} char_class_t;

static char normalize_char(int value)
{
    if (value < 0)
        value = (value % 256 + 256) % 256;
    else
        value = value % 256;
    return (char)value;
}

static void char_ctor(Object *this, va_list *args)
{
    char_class_t *self = (char_class_t *)this;

    if (!self || !args)
        raise("Invalid arguments for Char constructor");
    self->value = (char)va_arg(*args, int);
}

static void char_dtor(Object *this)
{
    if (!this)
        raise("Invalid arguments for Char destructor");
}

static char *char_to_string(Object *this)
{
    char_class_t *self = (char_class_t *)this;
    int size = snprintf(NULL, 0, "<Char (%c)>", self->value) + 1;
    char *str = malloc(size);

    if (!self)
        raise("Invalid object in to_string");
    if (!str)
        raise("Out of memory");
    snprintf(str, size, "<Char (%c)>", self->value);
    return str;
}

static Object *char_add(const Object *this, const Object *other)
{
    const char_class_t *self = (const char_class_t *)this;
    const char_class_t *other_char = (const char_class_t *)other;
    char result = normalize_char(self->value + other_char->value);

    if (!self || !other_char)
        raise("Invalid objects in addition");
    return new(Char, result);
}

static Object *char_sub(const Object *this, const Object *other)
{
    const char_class_t *self = (const char_class_t *)this;
    const char_class_t *other_char = (const char_class_t *)other;
    char result = normalize_char(self->value - other_char->value);

    if (!self || !other_char)
        raise("Invalid objects in subtraction");    
    return new(Char, result);
}

static Object *char_mul(const Object *this, const Object *other)
{
    const char_class_t *self = (const char_class_t *)this;
    const char_class_t *other_char = (const char_class_t *)other;
    char result = normalize_char(self->value * other_char->value);

    if (!self || !other_char)
        raise("Invalid objects in multiplication");    
    return new(Char, result);
}

static Object *char_div(const Object *this, const Object *other)
{
    const char_class_t *self = (const char_class_t *)this;
    const char_class_t *other_char = (const char_class_t *)other;
    char result = normalize_char(self->value / other_char->value);

    if (!self || !other_char)
        raise("Invalid objects in division");

    if (other_char->value == 0)
        raise("Division by zero");
    return new(Char, result);
}

static bool char_eq(const Object *this, const Object *other)
{
    const char_class_t *self = (const char_class_t *)this;
    const char_class_t *other_char = (const char_class_t *)other;

    if (!self || !other_char)
        raise("Invalid objects in equality comparison");
    return self->value == other_char->value;
}

static bool char_gt(const Object *this, const Object *other)
{
    const char_class_t *self = (const char_class_t *)this;
    const char_class_t *other_char = (const char_class_t *)other;

    if (!self || !other_char)
        raise("Invalid objects in greater than comparison");
    return self->value > other_char->value;
}

static bool char_lt(const Object *this, const Object *other)
{
    const char_class_t *self = (const char_class_t *)this;
    const char_class_t *other_char = (const char_class_t *)other;

    if (!self || !other_char)
        raise("Invalid objects in less than comparison");
    return self->value < other_char->value;
}

static const char_class_t _description = {
    {
        sizeof(char_class_t),
        "Char",
        &char_ctor,
        &char_dtor,
        &char_to_string,
        &char_add,
        &char_sub,
        &char_mul,
        &char_div,
        &char_eq,
        &char_gt,
        &char_lt
    },
    0
};

const Class *Char = (const Class *)&_description;
