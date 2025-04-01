/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** echo
*/

#include "shell.h"
#include "macro.h"
#include "my.h"

void my_echo(shell_t *shell)
{
    char *str = shell->parser->command->cmd + 5;

    my_cleanstr(str, "\t ");
    if (strcmp(COMMAND->arr[1], "-n") == 0) {
        if (COMMAND->arr[2])
            printf("%s", COMMAND->arr[2]);
        for (int i = 3; COMMAND->arr[i]; i++)
            printf(" %s", COMMAND->arr[i]);
        printf("%s%s%%%s%s\n", WHITE_BG, BLACK, BLACK_BG, WHITE);
    } else {
        if (COMMAND->arr[1])
            printf("%s", COMMAND->arr[1]);
        for (int i = 2; COMMAND->arr[i]; i++)
            printf(" %s", COMMAND->arr[i]);
        printf("\n");
    }
    fflush(stdout);
    shell->ret = 0;
}
