/*
** EPITECH PROJECT, 2024
** lib_my
** File description:
** my_str_to_word_array
*/

#include "my.h"

int count_words(char *str)
{
    int new_word = 1;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            new_word = 1;
        if ((str[i] == ' ' || str[i] == '#') && new_word == 1) {
            new_word = 0;
            count++;
        }
    }
    return (count + 1);
}

int word_position(char *str, int pos)
{
    int i = 0;

    while (str[pos + i] != '\0' && str[pos + i] != '\n' && str[pos + i] != ' '
        && str[pos + i] != '#')
        i++;
    while (str[pos + i] != '\0' && str[pos + i] != '\n' && (str[pos + i] == ' '
        || str[pos + i] == '#'))
        i++;
    return i;
}

int len_word(char *str, int pos, int isalpha)
{
    int i = pos;

    if (isalpha) {
        while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '#')
            i++;
    } else {
        while (str[i] && (str[i] == ' ' || str[i] == '#'))
            i++;
    }
    return (i - pos);
}

char **my_str_to_word_array(char *str)
{
    int nb_words = count_words(str) + my_count_char_alone(str, '#');
    char **tab = NULL;
    int nb_char = 0;
    int pos = len_word(str, 0, 0);

    tab = my_alloc_tab(nb_words);
    for (int i = 0; i < nb_words; i++) {
        nb_char = len_word(str, pos, 1);
        if (nb_char > 0) {
            tab[i] = my_alloc_str(nb_char);
            my_strncpy(tab[i], str + pos, nb_char);
        }
        pos = pos + word_position(str, pos);
    }
    return tab;
}
