/*
** EPITECH PROJECT, 2023
** bs_step2.c
** File description:
** bs_step2
*/

#include <stdio.h>

void array_1d_print_ints(int *array)
{
    for (int i = 0; array[i] != -1; i++)
        printf("%d\n", array[i]);
}

void main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
    array_1d_print_ints(array);
}