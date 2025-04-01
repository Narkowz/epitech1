/*
** EPITECH PROJECT, 2024
** Lingo
** File description:
** main.c
*/

#include "include/lingo.h"

int verif_file(char *buf)
{
    for (int i = 0; buf[i] != '\0'; i++)
        if (!isalpha(buf[i]) && buf[i] != '-' && buf[i] != '\n')
            return 84;
    return 0;
}

int count_line(char **words)
{
    int i = 0;

    for (; words[i] != NULL; i++);
    return i;
}

void free_everything(char *word, char **words, char *buf)
{
    free(word);
    free(buf);
    for (int i = 0; words[i] != NULL; i++)
        free(words[i]);
    free(words);
}

int main(int ac, char **av)
{
    char *buf = NULL;
    char **words = NULL;
    int rander = 0;
    char *word = NULL;

    if (ac != 2)
        return 84;
    buf = opening_file(av[1]);
    if (verif_file(buf) == 84)
        return 84;
    words = my_str_to_word_array(buf, words);
    print_header();
    rander = rand() % count_line(words);
    word = malloc(sizeof(char) * (strlen(words[rander]) + 1));
    if (game_loop(words[rander], word) == 0)
        printf("\nYou won!\n");
    else
        printf("\nYou lost!\n");
    free_everything(word, words, buf);
    return 0;
}
