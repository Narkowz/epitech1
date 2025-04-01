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
    printf("\033[2K\r");
    printf("%s❯ %s%s\n", BLUE, RESET, input);
    fflush(stdout);
}
