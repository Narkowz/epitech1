/*
** EPITECH PROJECT, 2023
** my str to word array
** File description:
** str to word array
*/

#include "../my/my.h"

int is_alphanumeric(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') || (c == ',') || (c == '.');
}

int count_words(const char *str)
{
    int count = 0;

    while (*str) {
        while (*str && !is_alphanumeric(*str))
            str++;
        if (*str && is_alphanumeric(*str))
            count++;
        while (*str && is_alphanumeric(*str))
            str++;
    }
    return count;
}

char *get_word(const char **str)
{
    size_t len;
    char *word;
    const char *start;

    while (**str && !is_alphanumeric(**str))
        (*str)++;
    start = *str;
    while (**str && is_alphanumeric(**str))
        (*str)++;
    len = *str - start;
    word = malloc(len + 1);
    strncpy(word, start, len);
    word[len] = '\0';
    return word;
}

char **my_str_to_word_array(const char *str)
{
    int words = count_words(str);
    char **array = malloc((words + 1) * sizeof(char *));

    for (int i = 0; i < words; i++)
        array[i] = get_word(&str);
    array[words] = NULL;
    return array;
}
