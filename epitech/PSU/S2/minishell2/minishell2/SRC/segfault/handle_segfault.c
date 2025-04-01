/*
** EPITECH PROJECT, 2024
** handle_segfault.c
** File description:
** handle_segfault
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

void handle_segfault(int result, int *value)
{
    if (WIFSIGNALED(result)) {
        result = WTERMSIG(result);
        if (result == SIGSEGV)
        mini_printf("Segmentation fault\n");
        *value = 139;
    }
    if (WIFEXITED(result))
        *value = WEXITSTATUS(result);
}
