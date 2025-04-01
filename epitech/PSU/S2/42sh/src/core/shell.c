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
#include "macro.h"
#include "glob.h"
#include "my.h"

static void highlight_history(char *input, size_t len)
{
    printf("\033[90m");
    fflush(stdout);
    my_putstr_after(input, (int)len, 1);
    printf("%s", RESET);
    fflush(stdout);
}

void search_in_history(shell_t *shell, int *index)
{
    save_t *current = shell->save->prec;
    size_t len = strlen(shell->save->input);

    if (!isatty(0))
        return;
    while (current) {
        if (!current->input)
            break;
        if (strncmp(shell->save->input, current->input, len) == 0 && !index) {
            highlight_history(current->input, len);
            break;
        }
        if (strncmp(shell->save->input, current->input, len) == 0 && index) {
            free(shell->save->input);
            shell->save->input = my_strdup(current->input);
            reset_and_move_back(shell, index);
            break;
        }
        current = current->prec;
    }
}

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
            reset_and_move_back(shell, index);
            search_in_history(shell, NULL);
        }
    } else if (c > 0 && c != 127 && c != 9) {
        shell->save->input = add_char(shell->save->input, *index, c);
        *index = *index + 1;
        reset_and_move_back(shell, index);
        search_in_history(shell, NULL);
    }
    if (c == 9 && isatty(0))
        handle_tab(shell, index);
    else
        shell->nb_tab = 0;
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

static int handle_last_char(shell_t *shell, char c, int *index)
{
    int len;

    if (c == 4)
        ctrl_d(shell);
    else if (c == '\n') {
        shell->nb_tab = 0;
        prompt_exe(shell->save->input);
        len = my_strlen(shell->save->input);
        shell->save->input = add_char(shell->save->input, len, '\0');
    } else
        return 1;
    return 0;
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
    long int readed = 0;

    create_buffer(shell, &index);
    readed = read(0, &c, 1);
    while (readed > 0 && c != 4 && c != '\n') {
        if (c == '\033')
            handle_arrow(c, &index, shell);
        else
            handle_text(shell, c, &index);
        fflush(stdout);
        readed = read(0, &c, 1);
    }
    if (readed == 0)
        return 1;
    if (handle_last_char(shell, c, &index) == 1)
        return 1;
    return 0;
}

/**
 * @brief main 42sh function
 * @param char** All the actual envirronment variables
 * @return The return value of the last command executed
 */
int shell(char **env, int open_rc)
{
    shell_t *shell = init_shell(get_shell(), env, open_rc);

    if (signal(SIGINT, handler) == SIG_ERR)
        return 1;
    while (true) {
        prompt(shell);
        if (get_input(shell) == 1)
            return shell->ret;
        if (!(shell->save->input) || my_strlen(shell->save->input) == 0)
            continue;
        save_command(shell);
        if (hold_parsing(shell) == 84 || verif_before_exec(shell) == 84) {
            shell->ret = 1;
            continue;
        }
        execute_all_commands(shell);
        free_shell_contain(shell);
    }
    return shell->ret;
}
