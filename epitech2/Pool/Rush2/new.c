/*
** EPITECH PROJECT, 2025
** new.c
** File description:
** Rush2 Pool Tech2
*/

#include "new.h"
#include "raise.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *obj;

    if (!class || class->__size__ <= 0)
        raise("Invalid class provided");
    obj = malloc(class->__size__);
    if (!obj)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__) {
        va_start(ap, class);
        class->__ctor__(obj, &ap);
        va_end(ap);
    }
    return obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj;

    if (!class || class->__size__ <= 0)
        raise("Invalid class provided");
    obj = malloc(class->__size__);
    if (!obj)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ && ap)
        class->__ctor__(obj, ap);
    return obj;
}

void delete(Object *ptr)
{
    const Class *class;

    if (!ptr)
        return;
    class = (const Class *)ptr;
    if (class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}
