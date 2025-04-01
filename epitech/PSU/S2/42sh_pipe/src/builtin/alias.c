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

static char *replace(char *str, char *a, char *b)
{
    char *start = str;
    char *result;
    char *dest;
    int nb;

    for (nb = 1; strstr(start, a); nb++)
        start = strstr(start, a) + my_strlen(a);
    result = malloc((size_t)
    ((my_strlen(str) + 1) + nb * (my_strlen(b) - my_strlen(a))));
    start = str;
    dest = result;
    while (strstr(start, a)) {
        strncpy(dest, start, (size_t)(strstr(start, a) - start));
        dest += strstr(start, a) - start;
        strncpy(dest, b, strlen(b));
        dest += my_strlen(b);
        start = strstr(start, a) + my_strlen(a);
    }
    strcpy(dest, start);
    return result;
}

void apply_alias(shell_t *shell)
{
    alias_t *current = shell->alias;

    while (current) {
        shell->save->input =
        replace(shell->save->input, current->initial, current->result);
        current = current->next;
    }
}

void my_alias(shell_t *shell)
{
    int fd = open("script/.42shrc", O_WRONLY | O_APPEND);
    alias_t *alias = malloc((size_t)sizeof(alias_t));

    alias->initial = strdup(COMMAND->arr[1]);
    alias->result = strdup(COMMAND->arr[2]);
    if (!shell->alias)
        shell->alias = alias;
    else
        shell->alias->next = alias;
    dprintf(fd, "alias '%s'='%s'\n", COMMAND->arr[1], COMMAND->arr[2]);
    close(fd);
    shell->ret = 0;
}
