/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** signal
*/

#include "usage.h"
#include "shell.h"
#include "my.h"

/**
 * @brief Is called for every Ctrl + C
 * @param int th enumber of the signal
 * @return Nothing
 */
void handler(int signum)
{
    shell_t *shell = NULL;

    if (signum || !isatty(0)) {
        shell = get_shell();
        prompt_exe(shell->save->input);
        free(shell->save->input);
        shell->save->input = NULL;
        prompt(NULL);
    }
}
