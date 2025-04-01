/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "../my/my.h"

void my_memset(void *dest, int c, size_t count)
{
    unsigned char *ptr = (unsigned char *)dest;

    for (size_t i = 0; i < count; i++)
        ptr[i] = (unsigned char)c;
}
