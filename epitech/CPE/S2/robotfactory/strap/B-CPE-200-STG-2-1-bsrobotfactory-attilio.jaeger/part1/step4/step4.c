/*
** EPITECH PROJECT, 2024
** step4.c
** File description:
** step4
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *path = NULL;
    int number = 192837;
    char str[40];
    char k = 'k';
    strcpy(str, "Corewar is swag!!");


    path = fopen("several-variables.yolo", "write-mode");
    fwrite(&number, sizeof(int), 1, path);
    fwrite(&k, sizeof(k), 1, path);
    fwrite(str, sizeof(str), 1, path);
    fclose(path);
    return 0;
}
