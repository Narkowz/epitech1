/*
** EPITECH PROJECT, 2024
** write_a_number_as_text.c
** File description:
** write_a_number_as_text
*/

#include <stdio.h>

int main(void)
{
    FILE *path = NULL;

    path = fopen("number-as-text.yolo", "write-mode");
    fputs("12345678", path);
    return 0;
}
