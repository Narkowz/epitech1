/*
** EPITECH PROJECT, 2024
** step5.c
** File description:
** step5
*/

#include <stdio.h>
#include <string.h>
#include "my.h"

int main(void)
{
    padding_t padd = {0};
    FILE *path = NULL;

    padd.number = 192837;
    padd.k = 'k';
    memset(padd.str, 0, 40);
    strcpy(padd.str, "Corewar is swag!!");
    path = fopen("one-structure.yolo", "write-mode");
    fwrite(&padd, sizeof(padd), 1, path);
    fclose(path);
    return 0;
}
