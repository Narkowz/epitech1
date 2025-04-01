/*
** EPITECH PROJECT, 2025
** concat.c Ex03
** File description:
** Ex 03 of Day04am of the pool Tech2
*/

#include <stdlib.h>
#include <stdio.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    *res = (int **)malloc(height * sizeof(int *));
    for (size_t i = 0; i < height; ++i)
        (*res)[i] = (int *)malloc(width * sizeof(int));
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            (*res)[i][j] = array[i * width + j];
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    (void)width;
    for (size_t i = 0; i < height; ++i)
        free(array[i]);
    free(array);
}
