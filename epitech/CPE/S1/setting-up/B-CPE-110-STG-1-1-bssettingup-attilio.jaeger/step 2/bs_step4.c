/*
** EPITECH PROJECT, 2023
** bs_step4.c
** File description:
** bs_step4
*/

#include <stdio.h>
#include <stdlib.h>


int array_2d_sum(int **array, int rows, int cols)
{
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
        }
    }
    return (sum);
}

void main(void)
{
    int **array = NULL;
    int rows = 5;
    int cols = 5;

    array = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        array[i] = malloc(sizeof(int) * cols);
    }
    array[0][0] = 1;
    array[0][1] = 2;
    array[0][2] = 3;
    array[0][3] = 4;
    array[0][4] = 5;
    array[1][0] = 6;
    array[1][1] = 7;
    array[1][2] = 8;
    array[1][3] = 9;
    array[1][4] = 10;
    array[2][0] = 11;
    array[2][1] = 12;
    array[2][2] = 13;
    array[2][3] = 14;
    array[2][4] = 15;
    printf("%d\n", array_2d_sum(array, rows, cols));
}