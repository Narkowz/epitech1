/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** save_command.c
*/

#include "shell.h"
#include "usage.h"
#include "my.h"
#include <stdlib.h>

void save_command(shell_t *shell)
{
    save_t *new_save = malloc(sizeof(save_t));

    shell->actual_save = NULL;
    new_save->raw_input = NULL;
    new_save->input = NULL;
    new_save->time = NULL;
    shell->save->next = new_save;
    shell->save->raw_input = my_strdup(shell->save->input);
    shell->save->time = get_hour();
    new_save->prec = shell->save;
    new_save->next = NULL;
    shell->save = new_save;
}
