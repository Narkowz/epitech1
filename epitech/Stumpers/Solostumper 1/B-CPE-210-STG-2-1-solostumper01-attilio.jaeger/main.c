/*
**EPITECH PROJECT, 2023
**main.c
**File description:
**main
*/

#include "include/my.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **tab_copy(char **origin)
{
    int i = 0;
    char **temp = malloc(sizeof(char *));

    for (; origin[i] != NULL; i++)
        temp[i] = strdup(origin[i]);
    temp[i] = NULL;
    return temp;
}

void main(int ac, char **av)
{
    char **words = my_str_to_word_array(av[1]);
    char **temp = tab_copy(words);
    printf("temp = %s", temp[1]);
    printf("words = %s", words[8]);
    int i = 0;
    int j = 0;
    int hint = 0;
    int *number_int = malloc((i + 1) * sizeof(int));
    int count = 0;

    for (; words[i] != NULL; i++) {
        printf("words : %s", words[i]);
        for (; temp[j] != NULL; j++) {
            printf(" temp : %s", temp[j]);
            hint = my_strcmp(words[i], temp[j]);
            printf(" hint = %d\n", hint);
            if (hint == 0) {
                count++;
                printf("count : %d", count);
            }
        }
        number_int[i] = count;
        count = 0;
        j = 0;
    }
    number_int[i] = -1;  // If needed to mark the end of the array
    int k = 0;
    for (; number_int[k] != -1; k++)  // Assuming zero is the end marker
        printf(" number : %d", number_int[k]);
    printf(" k = %d", k);
    free(number_int);  // Don't forget to free the allocated memory
}
