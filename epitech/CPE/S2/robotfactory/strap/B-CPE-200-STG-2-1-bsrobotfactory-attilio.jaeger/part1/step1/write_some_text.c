/*
** EPITECH PROJECT, 2024
** write_some_text.c
** File description:
** write_some_text
*/

#include <stdio.h>

int main(void)
{
    FILE *path = NULL;

    path = fopen("some-text.yolo", "write-mode");
    fputs("Hello bambino\n", path);
    return 0;
}
