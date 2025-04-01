/*
** EPITECH PROJECT, 2024
** write_a_number_as_int.c
** File description:
** write_a_number_as_int
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    FILE *path = NULL;
    int number = 12345678;

    path = fopen("number-as-int.yolo", "write-mode");
    fwrite(&number, sizeof(int), 1, path);
    fclose(path);
    return 0;
}
