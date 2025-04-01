/*
** EPITECH PROJECT, 2025
** concat.c Ex05
** File description:
** Ex 05 of Day04am of the pool Tech2
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void sort_int_array(int *array, size_t nmemb)
{
    int key = 0;
    size_t j;

    for (size_t i = 1; i < nmemb; i++) {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}

void sort_array(void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    qsort(array, nmemb, size, compar);
}
