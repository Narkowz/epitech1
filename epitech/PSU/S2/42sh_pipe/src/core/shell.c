/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** shell
*/

#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usage.h"
#include "shell.h"
#include "my.h"


/**
 * @brief Is called for every text input in the 42sh
 * @param shell_t* The main sheel structure
 * @param char The char that was typed by the user
 * @param int* the index of where to update the input
 * @return Nothing but update the shell_struct
 */
static void handle_text(shell_t *shell, char c, int *index)
{
    if (!shell->save->input)
        shell->save->input = my_alloc_str(1024);
    if (c == 127) {
        if (*index > 0) {
            *index = *index - 1;
            shell->save->input = delete_char(shell->save->input, *index);
            reset_command(shell->save->input);
            move_back_cursor(shell->save->input, *index);
        }
    } else if (c > 0) {
        shell->save->input = add_char(shell->save->input, *index, c);
        *index = *index + 1;
        reset_command(shell->save->input);
        move_back_cursor(shell->save->input, *index);
    }
}

static void create_buffer(shell_t *shell, int *index)
{
    if (shell->save->input) {
        *index = (int)strlen(shell->save->input);
        printf("%s", shell->save->input);
        fflush(stdout);
    } else
        shell->save->input = my_alloc_str(1024);
}

/**
 * @brief This is the main read funciton in 42sh
 *        It read and analyse every user input
 * @param shell_t* The main sheel structure
 * @return int The return value of the last command executed
 */
int get_input(shell_t *shell)
{
    char c;
    int index = 0;

    create_buffer(shell, &index);
    while (read(0, &c, 1) > 0 && c != 4 && c != '\n') {
        if (c == '\033')
            handle_arrow(c, &index, shell);
        else
            handle_text(shell, c, &index);
        fflush(stdout);
    }
    if (c == 4)
        ctrl_d(shell);
    else if (c == '\n') {
        prompt_exe(shell->save->input);
        add_char(shell->save->input, index, '\0');
    } else
        return 1;
    return 0;
}

/**
 * @brief main 42sh function
 * @param char** All the actual envirronment variables
 * @return The return value of the last command executed
 */
int shell(char **env)
{
    shell_t *shell = init_shell(get_shell(), env);

    if (signal(SIGINT, handler) == SIG_ERR)
        return 1;
    while (true) {
        prompt(shell);
        if (get_input(shell) == 1)
            return shell->ret;
        if (!(shell->save->input) || my_strlen(shell->save->input) == 0)
            continue;
        hold_parsing(shell);
        save_command(shell);
        if (verif_before_exec(shell) == 84) {
            shell->ret = 1;
            continue;
        }
        execute_all_commands(shell);
        free_shell_contain(shell);
    }
    return shell->ret;
}
