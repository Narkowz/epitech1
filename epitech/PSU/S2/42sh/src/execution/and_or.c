/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** and_or
*/

#include "main.h"
#include "shell.h"
#include "macro.h"

command_t *handle_or(shell_t *shell, command_t *command)
{
    int skip = 0;

    while (command && command->sep == T_OR && skip == 0) {
        execute_one_command(shell);
        if (shell->ret == 0) {
            skip = 1;
            break;
        }
        command = command->prev;
        COMMAND = COMMAND->prev;
    }
    if (skip != 0)
        while (command && (command->sep == T_OR || command->sep == T_OTHER)) {
            command = command->prev;
            COMMAND = COMMAND->prev;
        }
    return command;
}

command_t *handle_and(shell_t *shell, command_t *command)
{
    int skip = 0;

    while (command && command->sep == T_AND && skip == 0) {
        execute_one_command(shell);
        if (shell->ret != 0) {
            skip = 1;
            break;
        }
        command = command->prev;
        COMMAND = COMMAND->prev;
    }
    if (skip != 0)
        while (command && (command->sep == T_AND || command->sep == T_OTHER)) {
            command = command->prev;
            COMMAND = COMMAND->prev;
        }
    return command;
}
