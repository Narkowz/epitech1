/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** redirect.c
*/

#include "shell.h"

int open_redirect(int sep, char *filename)
{
    int val = -2;

    if (sep == 4)
        val = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else
        val = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    return val;
}

command_t *handle_redirect(shell_t *shell, command_t *cmd)
{
    printf("We redirect %s\n", cmd->cmd);
    return handle_rright_or_drright(shell, cmd, cmd->sep);
}
