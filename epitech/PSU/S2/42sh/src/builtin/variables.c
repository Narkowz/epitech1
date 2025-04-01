/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** variables
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "string.h"
#include "shell.h"
#include "macro.h"
#include "my.h"

void add_to_var(shell_t *shell, char *var_name, char *var_value)
{
    var_t *current = shell->var;
    var_t *new;

    while (current) {
        if (strcmp(current->var_name, var_name) == 0) {
            free(current->var_value);
            current->var_value = my_strdup(var_value);
            return;
        }
        current = current->next;
    }
    new = malloc((size_t)sizeof(var_t));
    new->var_name = my_strdup(var_name);
    new->var_value = my_strdup(var_value);
    new->next = shell->var;
    shell->var = new;
}

static void display_var(shell_t *shell)
{
    var_t *current = shell->var;

    while (current) {
        printf("%s\t%s\n", current->var_name, current->var_value);
        current = current->next;
    }
}

static int is_valid_var(char *var)
{
    if ((var[0] < 'A' || (var[0] > 'Z'
        && var[0] < 'a') || var[0] > 'z') && var[0] != '_') {
        my_putstr("set: Variable name must begin with a letter.\n", 2);
        return false;
    }
    for (int i = 1; var[i] != '\0'; i++) {
        if ((var[i] < '0' || (var[i] > '9' && var[i] < 'A') ||
            (var[i] > 'Z' && var[i] < 'a') || var[i] > 'z') &&
            var[i] != '_') {
            printf("set: ");
            printf("Variable name must contain alphanumeric characters.\n");
            return false;
        }
    }
    return true;
}

void my_set(shell_t *shell)
{
    int index_eq = 0;
    char var_value[256] = "";

    if (!COMMAND->arr[1]) {
        display_var(shell);
        return;
    } else if (!is_valid_var(COMMAND->arr[1])) {
        shell->ret = 1;
        return;
    }
    for (int i = 1; COMMAND->arr[i]; i++)
        if (strcmp(COMMAND->arr[i], "=") == 0)
            index_eq = i;
    if (COMMAND->arr[index_eq + 1] && index_eq != 0)
        strcpy(var_value, COMMAND->arr[index_eq + 1]);
    for (int i = 1; COMMAND->arr[i]; i++) {
        if (strcmp(COMMAND->arr[i], "=") == 0)
            break;
        add_to_var(shell, COMMAND->arr[i], var_value);
    }
}
