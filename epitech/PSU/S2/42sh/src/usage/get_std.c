/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** get_original_stdout.c
*/

#include <sys/resource.h>
#include "builtin.h"
#include "shell.h"
#include "macro.h"
#include "my.h"

int get_original_stdin(void)
{
    static int original_fd = -2;

    if (original_fd == -2)
        original_fd = dup(STDIN_FILENO);
    return original_fd;
}

int get_original_stdout(void)
{
    static int original_fd = -2;

    if (original_fd == -2)
        original_fd = dup(STDOUT_FILENO);
    return original_fd;
}

void reset_std(void)
{
    dup2(get_original_stdin(), STDIN_FILENO);
    dup2(get_original_stdout(), STDOUT_FILENO);
}
