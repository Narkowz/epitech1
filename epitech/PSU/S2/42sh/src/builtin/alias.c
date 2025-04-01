/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** alias
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "shell.h"
#include "macro.h"
#include "my.h"

static char *replace(char *str, alias_t *alias, int *result)
{
    char **arr = my_str_to_word_array(str);

    for (int i = 0; arr && arr[i]; i++) {
        if (my_strcmp(arr[i], alias->initial) == 0) {
            free(arr[i]);
            arr[i] = my_strdup(alias->result);
            *result = alias->loop;
        }
    }
    return tab_to_str(arr);
}

int apply_alias(shell_t *shell)
{
    alias_t *current = shell->alias;
    int result = 0;

    if (strncmp("alias ", shell->save->prec->input, strlen("alias ")) == 0) {
        return 0;
    }
    while (current && result == 0) {
        shell->save->prec->input =
        replace(shell->save->prec->input, current,
        &result);
        current = current->next;
    }
    if (result == 1)
        return 1;
    return 0;
}

static int check_for_loop(command_t *cmd)
{
    char **temp = my_str_to_word_array(cmd->arr[2]);

    for (int i = 0; temp[i]; i++) {
        if (my_strcmp(temp[i], cmd->arr[1]) == 0) {
            return 1;
        }
    }
    return 0;
}

void create_new_alias(shell_t *shell)
{
    int fd;
    alias_t *alias = malloc((size_t)sizeof(alias_t));

    alias->loop = check_for_loop(COMMAND);
    alias->initial = strdup(COMMAND->arr[1]);
    alias->result = strdup(COMMAND->arr[2]);
    alias->next = shell->alias;
    shell->alias = alias;
    if (shell->open_rc) {
        fd = open("script/.42shrc", O_WRONLY | O_APPEND);
        dprintf(fd, "alias '%s'='%s'\n", COMMAND->arr[1], COMMAND->arr[2]);
        close(fd);
    }
    shell->ret = 0;
}

void display_existing_alias(shell_t *shell)
{
    alias_t *current = shell->alias;
    char *temp = my_strdup(COMMAND->arr[1]);

    while (current) {
        if (my_strcmp(current->initial, temp) == 0) {
            printf("%s\n", current->result);
            fflush(stdout);
            return;
        }
        current = current->next;
    }
}

void my_alias(shell_t *shell)
{
    alias_t *current = shell->alias;
    int len = my_tab_len(COMMAND->arr);

    if (len == 3)
        create_new_alias(shell);
    if (len == 2)
        display_existing_alias(shell);
    if (len == 1) {
        while (current) {
            printf("%s\t%s\n", current->initial, current->result);
            current = current->next;
        }
    }
}
