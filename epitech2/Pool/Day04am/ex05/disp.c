/*
** EPITECH PROJECT, 2025
** concat.c Ex05
** File description:
** Ex 05 of Day04am of the pool Tech2
*/

#include <string.h>
#include <stdio.h>

void disp_int_array(const int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void disp_array(const void *array, size_t nmemb, size_t size,
    void (*print)(const void *))
{
    const char *arr = (const char *)array;

    for (size_t i = 0; i < nmemb; i++)
        print(arr + i * size);
}
