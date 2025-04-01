/*
** EPITECH PROJECT, 2024
** MY_STR_TO_WORD_ARRAY
** File description:
** my_str_to_word_array
*/

#include "crocus.h"

int is_valid_char(char c)
{
    if (c == '\n' || c == '\0')
        return (0);
    return (1);
}

int make_nbwords(const char *str)
{
    int nbwords = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_valid_char(str[i]) == 0) {
            nbwords = nbwords + 1;
        }
    }
    return (nbwords);
}

int make_lenword(const char *str, int word)
{
    int lenword = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_valid_char(str[i]) == 1 && word == 0)
            lenword++;
        if (is_valid_char(str[i]) != 1)
            word = word - 1;
    }
    return (lenword);
}

char **my_str_to_word_array(const char *str, char **tab)
{
    int nbwords = make_nbwords(str);
    int lenword;
    int i = 0;
    int index;

    tab = malloc(sizeof(char *) * (nbwords + 1));
    tab[nbwords] = 0;
    for (int word = 0; word < nbwords; word++) {
        index = 0;
        lenword = make_lenword(str, word);
        tab[word] = malloc(sizeof(char) * (lenword) + 1);
        for (i; is_valid_char(str[i]) == 1; i++) {
            tab[word][index] = str[i];
            index++;
        }
        tab[word][index] = '\0';
    i++;
    }
    return (tab);
}
