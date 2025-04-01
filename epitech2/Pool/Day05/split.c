/*
** EPITECH PROJECT, 2025
** split.c
** File description:
** split
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

static int count_words(const char *str, char *separator)
{
    int count = 1;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == separator[0])
            count++;
    return count;
}

static char *allocate_and_copy(const char *str, int start, int end)
{
    char *word = NULL;
    int length = 0;

    length = end - start;
    word = malloc((length + 1) * sizeof(char));
    if (!word)
        return NULL;
    strncpy(word, &str[start], length);
    word[length] = '\0';
    return word;
}

static char **head(const string_t *this, char separator)
{
    char sep[2] = {separator, '\0'};
    int word_count = count_words(this->str, sep);
    char **result = malloc((word_count + 1) * sizeof(char *));
    int start = 0;
    int i = 0;
    int end = 0;

    for (int j = 0; this->str[j] != '\0'; j++) {
        if (this->str[j] == sep[0] || this->str[j + 1] == '\0') {
            end = (this->str[j] == sep[0]) ? j : j + 1;
            result[i] = allocate_and_copy(this->str, start, end);
            i++;
            start = j + 1;
        }
    }
    result[word_count] = NULL;
    return result;
}

char **split_c(const string_t *this, char separator)
{
    if (!this || !this->str)
        return NULL;
    return head(this, separator);
}

string_t **split_s(const string_t *this, char separator)
{
    char sep[2] = {separator, '\0'};
    char **split_result = split_c(this, separator);
    int i = 0;
    string_t **result = NULL;

    if (!split_result)
        return NULL;
    result = malloc((count_words(this->str, sep) + 1) * sizeof(string_t *));
    if (!result)
        return NULL;
    for (i = 0; split_result[i]; i++) {
        result[i] = malloc(sizeof(string_t));
        if (!result[i])
            return NULL;
        result[i]->str = split_result[i];
    }
    result[i] = NULL;
    free(split_result);
    return result;
}
