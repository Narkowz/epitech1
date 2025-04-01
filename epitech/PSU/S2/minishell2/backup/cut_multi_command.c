/*
** EPITECH PROJECT, 2024
** cut_multi_command.c
** File description:
** cut_multi_command
*/

#include "include/minishell.h"
#include "include/my.h"

void add_node(list_t **multi, char *command, int ispipe)
{
    list_t *header = *multi;
    list_t *tmp = malloc(sizeof(list_t));

    tmp->ispipe = ispipe;
    tmp->command = my_strdup(command);
    tmp->next = NULL;
    if (header == NULL) {
        *multi = tmp;
        return;
    }
    while (header->next != NULL)
        header = header->next;
    header->next = tmp;
}

char delimiter_tester(char *command, int count, int i, int k)
{
    char delim = '\0';

    for (; command[k] != '\0'; k++) {
        if (command[k] == ';' || command[k] == '|') {
            count++;
            delim = command[k];
            k++;
        }
        if (count == i)
            break;
        if (k == my_strlen(command) - 1 && command[k] != ';' &&
            command[k] != '|')
            delim = ';';
    }
    return delim;
}

void cut_multi_command(env_t *my_env, char *command, list_t **multi)
{
    int i = 0;
    char *token = my_strdup(command);
    list_t *tmp = NULL;
    list_t *current = NULL;
    int count = 0;
    char delim = '\0';
    int k = 0;
    int ispipe = 0;

    token = strtok(token, ";|");
    while (token != NULL) {
        i += 1;
        ispipe = 0;
        if (delimiter_tester(command, count, i, k) == '|')
            ispipe += 1;
        add_node(&tmp, token, ispipe);
        token = strtok(NULL, ";|");
    }
    *multi = tmp;
}
