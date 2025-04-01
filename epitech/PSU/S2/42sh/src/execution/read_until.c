/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** read_until.c
*/

#include "my.h"
#include "shell.h"

static char *get_new_line(FILE *fd)
{
    char *line = NULL;
    char *final = NULL;
    size_t len = 0;

    my_putstr("? ", 1);
    if (getline(&line, &len, fd) == -1)
        return NULL;
    if (!line)
        return NULL;
    final = my_alloc_str(my_strlen(line));
    for (int i = 0; line[i] && line[i] != '\n'; i++)
        final[i] = line[i];
    free(line);
    return final;
}

void read_until(char *end_name, int tmp_fd)
{
    char *new_line = NULL;

    disable_raw_mode();
    do {
        if (new_line) {
            my_putstr(new_line, tmp_fd);
            my_putchar('\n', tmp_fd);
        }
        free(new_line);
        new_line = get_new_line(stdin);
    } while (new_line && my_strcmp(new_line, end_name) != 0);
    enable_raw_mode();
}
