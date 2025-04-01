/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** history
*/

#include <time.h>
#include "shell.h"
#include "usage.h"

void my_history(shell_t *shell)
{
    save_t *current = shell->save;
    int index = 1;

    while (current->prec) {
        current = current->prec;
    }
    while (current) {
        if (current->input)
            printf("     ");
        for (int i = index; i >= 10; i = i / 10)
            printf("\b");
        if (current->input)
            printf("%d  %s\t%s\n", index, current->time, current->raw_input);
        current = current->next;
        index++;
        fflush(stdout);
    }
    shell->ret = 0;
}
