/*
** EPITECH PROJECT, 2024
** addWordToString.c
** File description:
** ici
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_strcat(char **str1, char *str2)
{
    size_t len1 = my_strlen(*str1);
    size_t len2 = my_strlen(str2);
    size_t newLength = len1 + len2 + 1;
    char *result = malloc(sizeof(char *) * len1);

    if (result != NULL) {
        my_strcpy(result, *str1);
        free(*str1);
        *str1 = malloc(sizeof(char *) * newLength);
        my_strcpy(*str1, result);
        free(result);
        for (size_t i = 0; i < len2; ++i)
            (*str1)[len1 + i] = str2[i];
        (*str1)[len1 + len2] = '\0';
    } else
        return NULL;
    return result;
}

int add_word_to_string(char *source, char *word, char **result)
{
    size_t newLength = my_strlen(source) + my_strlen(word) + 2;

    *result = malloc(sizeof(char *) * newLength);
    if (*result != NULL) {
        my_strcpy(*result, source);
        my_strcat(result, " ");
        my_strcat(result, word);
        return 0;
    } else
        return 84;
}
