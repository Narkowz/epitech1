/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "my.h"

int my_fgetc(FILE *stream)
{
    unsigned char c;
    size_t result = fread(&c, 1, 1, stream);

    if (result == 0)
        return -1;
    else
        return (int)c;
}
