/*
** EPITECH PROJECT, 2024
** Lingo
** File description:
** game_loop.c
*/

#include "../include/lingo.h"

char *init_word(char *word, char *result)
{
    int i = 1;

    word[0] = result[0];
    for (; result[i] != '\0'; i++)
        word[i] = '*';
    word[i] = '\0';
    return word;
}

void gest_error(char *answer, size_t size, char *result)
{
    int len_result = strlen(result);
    int len_answer = strlen(answer) - 1;

    while (len_answer != len_result) {
        if (len_answer < len_result)
            printf("Word too short. Retry.\n");
        else
            printf("Word too long. Retry.\n");
        printf(">");
        getline(&answer, &size, stdin);
        len_result = strlen(result);
        len_answer = strlen(answer) - 1;
    }
}

int is_in(char c, char *result)
{
    for (int i = 0; i != strlen(result); i++) {
        if (c == result[i])
            return 1;
    }
    return 0;
}

char *verif_answer(char *answer, char *result, char *word)
{
    for (int i = 0; i != strlen(result); i++) {
        if (answer[i] == result[i])
            word[i] = result[i];
        if (is_in(answer[i], result) == 1 && answer[i] != result[i])
            word[i] = '?';
    }
    return word;
}

int game_loop(char *result, char *word)
{
    char *answer = NULL;
    size_t size = 0;

    word = init_word(word, result);
    printf("%s\n", word);
    for (int i = 1; i < strlen(result) + 1; i++) {
        printf("\nRound %d\n>", i);
        getline(&answer, &size, stdin);
        gest_error(answer, size, result);
        word = verif_answer(answer, result, word);
        printf("%s\n", word);
        if (strcmp(word, result) == 0) {
            free(answer);
            return 0;
        }
        word = init_word(word, result);
    }
    free(answer);
    return 1;
}
