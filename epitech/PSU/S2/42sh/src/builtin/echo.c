/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** echo
*/

#include "shell.h"
#include "macro.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

static char *replace_with_value(char *str, char *a, char *b)
{
    int len = my_strlen(b) - 1;
    int start = 0;
    char *temp = NULL;

    for (int i = 0; b[i]; i++) {
        if (i >= len || i + start >= my_strlen(str) - 1)
            str = add_char(str, i + start, b[i]);
        else
            str[i + start] = b[i];
    }
    for (int i = 0; i <= my_strlen(str) - len; i++) {
        str = delete_char(str, i + start + len + 1);
    }
    temp = my_strdup(str);
    free(str);
    return temp;
}

static char *replace(char *str, char *a, char *b, int *rep)
{
    int index = 0;

    for (int i = 0; str && str[i]; i++) {
        if (str[i] == a[index] && index < my_strlen(a) - 1)
            index++;
        if (str[i] == a[index] && index == my_strlen(a) - 1) {
            str = replace_with_value(str, a, b);
            index = 0;
            *rep = 1;
        }
    }
    return str;
}

static char *convert_to_str(void *val)
{
    char *str = malloc(20);

    snprintf(str, 20, "%d", *((int *)val));
    return str;
}

char *add_dollar(const char *str)
{
    size_t len = strlen(str);
    char *new_string = malloc((len + 2) * sizeof(char));

    new_string[0] = '$';
    strcpy(new_string + 1, str);
    return new_string;
}

static char *handle_last(char *str, shell_t *shell, int *rep)
{
    pid_t pid = getpid();

    if (my_strcmp(str, "$?") == 0) {
        str = replace(str, "$?", convert_to_str(&shell->ret), rep);
        str[my_strlen(str) - 1] = '\0';
    }
    if (my_strcmp(str, "$$") == 0)
        str = replace(str, "$$", convert_to_str(&pid), rep);
    return str;
}

static char *replace_var(shell_t *shell, char *str, int *temp)
{
    var_t *current = shell->var;
    int rep = 0;

    if (!str || str[0] != '$')
        return str;
    while (current && rep == 0) {
        str = replace(str, add_dollar(current->var_name), current->var_value,
        &rep);
        current = current->next;
    }
    str = handle_last(str, shell, &rep);
    if (rep == 0) {
        *temp = 1;
        dprintf(2, "%s: Undefined variable.\n", delete_char(str, 0));
        shell->ret = 1;
    }
    return str;
}

static int replace_all_var(shell_t *shell)
{
    int temp = 0;

    for (int i = 0; COMMAND->arr[i]; i++) {
        COMMAND->arr[i] = replace_var(shell, COMMAND->arr[i], &temp);
        if (temp == 1)
            return 1;
    }
    return 0;
}

void my_echo(shell_t *shell)
{
    if (replace_all_var(shell) == 1)
        return;
    if (COMMAND->arr[1] && strcmp(COMMAND->arr[1], "-n") == 0) {
        if (COMMAND->arr[2])
            printf("%s", COMMAND->arr[2]);
        for (int i = 3; COMMAND->arr[i]; i++)
            printf(" %s", COMMAND->arr[i]);
        printf("%s%s%%%s%s\n", WHITE_BG, BLACK, BLACK_BG, WHITE);
    } else {
        if (COMMAND->arr[1])
            printf("%s", COMMAND->arr[1]);
        for (int i = 2; COMMAND->arr[1] && COMMAND->arr[i]; i++)
            printf(" %s", COMMAND->arr[i]);
        printf("\n");
    }
    fflush(stdout);
    shell->ret = 0;
}
