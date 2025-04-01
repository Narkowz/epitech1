/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** arrow.c
*/

#include "my.h"
#include "shell.h"
#include "macro.h"

void move_back_cursor(char *input, int index)
{
    int len = (int)strlen(input);

    for (int i = 0; i < len - index; i++) {
        dprintf(1, "\x1b[D");
    }
}

void move_cursor(int add, int *index)
{
    *index = *index + add;
    if (add < 0) {
        dprintf(1, "\x1b[D");
    } else if (add > 0) {
        dprintf(1, "\x1b[C");
    }
}

static void go_last_save(shell_t *shell, int *index)
{
    if (shell->save->prec) {
        shell->save = shell->save->prec;
        *index = my_strlen(shell->save->input);
        reset_command(shell->save->input);
    }
}

static void go_next_save(shell_t *shell, int *index)
{
    if (shell->save->next) {
        shell->save = shell->save->next;
        *index = my_strlen(shell->save->input);
        reset_command(shell->save->input);
    }
}

/**
 * @brief Is called for every arrow the user type
 * @param char The char that was typed by the user
 * @param int* the index of where to update the input
 * @param shell_t* The main sheel structure
 * @return Nothing but update the shell_struct
 */
void handle_arrow(char c, int *index, shell_t *shell)
{
    read(0, &c, 1);
    if (c == '[') {
        read(0, &c, 1);
        if (c == 'A')
            go_last_save(shell, index);
        if (c == 'B')
            go_next_save(shell, index);
        if (c == 'C' && *index < (int)strlen(shell->save->input))
            move_cursor(1, index);
        if (c == 'D' && *index > 0)
            move_cursor(-1, index);
    }
}
