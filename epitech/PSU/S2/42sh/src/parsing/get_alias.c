/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** get_alias
*/

#include "usage.h"
#include "shell.h"
#include "main.h"
#include "my.h"
#include "builtin.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void stock_alias(shell_t *shell, char *str)
{
    char a[1024];
    char b[1024];
    alias_t *alias = malloc((size_t)sizeof(alias_t));

    if (sscanf(str, "alias '%49[^']'='%49[^']'", a, b) == 2) {
        alias->initial = strdup(a);
        alias->result = strdup(b);
        alias->next = shell->alias;
        shell->alias = alias;
    }
}

void get_alias(shell_t *shell)
{
    char *line = NULL;
    size_t size = 0;
    FILE *file = fopen("script/.42shrc", "r");

    while (getline(&line, &size, file) != -1)
        stock_alias(shell, line);
    fclose(file);
    free(line);
}
