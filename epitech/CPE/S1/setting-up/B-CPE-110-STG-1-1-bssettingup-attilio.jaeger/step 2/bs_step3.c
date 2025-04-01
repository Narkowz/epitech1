/*
** EPITECH PROJECT, 2023
** bs_step3.c
** File description:
** bs_step3
*/

#include <stdio.h>

int array_id_sum(int *array, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += array[i];
    return (sum);
}

int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d\n", array_id_sum(array, 10));
    return (0);
}