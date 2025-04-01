/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** redirect.c
*/

#include "shell.h"
#include <sys/stat.h>

static int check_good_file(char *filename)
{
    if (access(filename, F_OK) != 0) {
        printf("%s: No such file or directory.\n", filename);
        return -1;
    }
    if (access(filename, R_OK) != 0) {
        printf("%s: Permission denied.\n", filename);
        return -1;
    }
    return 0;
}

int open_redirect(int sep, char *filename)
{
    int fd;

    if (sep == 5 && check_good_file(filename) == -1)
        return -1;
    if (sep == 4)
        return open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (sep == 2)
        return open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (sep == 5)
        return open(filename, O_RDONLY);
    if (sep == 3) {
        fd = open("file", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        read_until(filename, fd);
        close(fd);
        return open("file", O_RDONLY, 0666);
    }
    return -1;
}

command_t *handle_redirect(shell_t *shell, command_t *cmd)
{
    if (cmd->sep == T_RRIGHT || cmd->sep == T_DRRIGHT)
        return handle_rright_or_drright(shell, cmd, cmd->sep);
    if (cmd->sep == T_RLEFT || cmd->sep == T_DRLEFT)
        return handle_rleft_or_drleft(shell, cmd, cmd->prev->sep);
    return NULL;
}
