/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** reset_command.c
*/

#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "macro.h"
#include "my.h"


/**
 * @brief Reset what is dispalyed and move the cursor at the end
 * @param shell_t *shell the shell where teh input is saved.
 * @param int *index, the index of the actual write
 * @return Nothing
 */
void reset_and_move_back(shell_t *shell, int *index)
{
    *index = my_strlen(shell->save->input);
    reset_command(shell->save->input);
    move_back_cursor(shell->save->input, *index);
}

/**
 * @brief Reset what is display in the terminal to put a new version
 * @param char* The input that we need to print
 * @return Nothing
 */
void reset_command(char *input)
{
    if (!isatty(0))
        return;
    printf("\033[2K\r");
    prompt(NULL);
    printf("%s", input);
    fflush(stdout);
}

/**
 * @brief Reset what is display in the terminal to put a new version
 * @param char* The input that we need to print
 * @return Nothing
 */
void prompt_exe(char *input)
{
    if (!isatty(0))
        return;
    if (input)
        move_back_cursor(input, my_strlen(input));
    printf("\033[2K\r");
    if (input)
        printf("%s❯ %s%s\n", BLUE, RESET, input);
    else
        printf("%s❯ %s\n", BLUE, RESET);
    fflush(stdout);
}
