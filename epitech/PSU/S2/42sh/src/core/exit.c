/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** exit
*/

#include "shell.h"
#include "my.h"
#include "macro.h"

/**
 * @brief Is called for every Ctrl + D
 * \note End the 42sh if the input is empty
 * Or write again the same input on the next line
 * @param shell_t* The main sheel structure
 * @return Nothing
 */
void ctrl_d(shell_t *shell)
{
    int ret = shell->ret;

    if (shell->save->input && my_strlen(shell->save->input) > 0) {
        prompt_exe(shell->save->input);
        prompt(shell);
        get_input(shell);
        return;
    }
    if (isatty(0))
        prompt_exe(EXIT);
    if (shell)
        free_shell(shell);
    disable_raw_mode();
    exit(ret);
}

void exit_minishell(shell_t *shell)
{
    int ret = shell->ret;

    if (isatty(0))
        my_putstr(EXIT, 1);
    free_shell(shell);
    disable_raw_mode();
    exit(ret);
}
