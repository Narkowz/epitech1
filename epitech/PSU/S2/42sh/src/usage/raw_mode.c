/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** raw_mode.c
*/

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "my.h"

struct termios original_termios;

/**
 * @brief This allow to enable raw mode:
 *        After this, we will not be able to see everything
 *        that the user write if we dont print it
 * @returns Nothing
 */
void enable_raw_mode(void)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);
    original_termios = raw;
    raw.c_lflag &= (tcflag_t) ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    if (!isatty(0))
        return;
    printf("\033[?7l");
    fflush(stdout);
    return;
}

void disable_raw_mode(void)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
    if (!isatty(0))
        return;
    printf("\033[?7h");
    fflush(stdout);
}
