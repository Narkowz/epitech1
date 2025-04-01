/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** error.c
*/

#include "shell.h"
#include "my.h"

void invalid_command(command_t *command, shell_t *shell)
{
    dprintf(2, "%s: Command not found.\n", command->arr[0]);
    fflush(stderr);
    shell->ret = 1;
}

void err_exec(char *copy, char *message)
{
    my_putstr(copy, 2);
    my_putstr(message, 2);
    free(copy);
    exit(1);
}

void glob_error(char *copy, char *message)
{
    my_putstr(copy, 2);
    my_putstr(message, 2);
    free(copy);
}
