/*
** EPITECH PROJECT, 2025
** concat.c Ex05
** File description:
** Ex 05 of Day04am of the pool Tech2
*/

#include <string.h>
#include <stdio.h>

void for_loop(int *is_duplicate, size_t unique_count, int *array, int i)
{
    for (size_t j = 0; j < unique_count; j++)
        if (array[i] == array[j]) {
            (*is_duplicate) = 1;
            break;
        }
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    size_t unique_count = 1;
    int is_duplicate = 0;

    for (size_t i = 1; i < nmemb; i++) {
        is_duplicate = 0;
        for_loop(&is_duplicate, unique_count, array, i);
        if (!is_duplicate) {
            array[unique_count] = array[i];
            unique_count++;
        }
    }
    return unique_count;
}

size_t uniq_array(void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    char *arr = (char *)array;
    size_t unique_count = 1;
    void *current_element;
    void *previous_element;
    int is_unique = 1;

    for (size_t i = 1; i < nmemb; i++) {
        current_element = arr + i * size;
        is_unique = 1;
        for (size_t j = 0; j < unique_count; j++) {
            previous_element = arr + j * size;
            is_unique = (compar(current_element, previous_element) == 0) ? 0 :
                is_unique;
        }
        unique_count += is_unique && (memcpy(arr + unique_count * size,
            current_element, size), 1);
    }
    return unique_count;
}
