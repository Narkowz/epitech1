/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** globing
*/

#include "usage.h"
#include "shell.h"
#include "my.h"
#include <glob.h>

static char where_to_glob(char *str)
{
    if (my_locate_char(str, '*') != -1)
        return '*';
    if (my_locate_char(str, '?') != -1)
        return '?';
    return 0;
}

static int count_arr_size(char **arr)
{
    int cnt = 0;

    for (int pos = 0; arr[pos]; pos++) {
        if (where_to_glob(arr[pos]) == 0)
            ++cnt;
    }
    return cnt + 1;
}

static void append_pathv_to_arr(char ***arr, char **pathv, int *pos)
{
    for (int i = 0; pathv[i]; i++) {
        (*arr)[*pos] = strdup(pathv[i]);
        *pos += 1;
    }
}

char **replace_globed(command_t *tmp, char **pathv, int i)
{
    int arrsize = count_arr_size(tmp->arr);
    char **arr = malloc(sizeof(char *) * ((unsigned long)(arrsize + i + 2)));
    int pos = 0;

    for (int j = 0; tmp->arr[j]; ++j) {
        if (where_to_glob(tmp->arr[j]) != 0) {
            append_pathv_to_arr(&arr, pathv, &pos);
            continue;
        }
        arr[pos] = my_strdup(tmp->arr[j]);
        ++pos;
    }
    arr[pos] = NULL;
    return arr;
}

void update_cmd(command_t *tmp, char *str)
{
    glob_t info = {0};
    int index = 0;

    glob(str, 0, NULL, &info);
    if (!info.gl_pathv) {
        glob_error(str, ": No match.\n");
        return;
    }
    tmp->arr = replace_globed(tmp, info.gl_pathv, index);
}

void hold_globing_in_cmd(command_t *tmp)
{
    char **arr = NULL;
    char c = 0;

    if (!tmp || !tmp->cmd)
        return;
    arr = simple_str_to_array(strdup(tmp->cmd), ' ');
    for (int i = 0; arr && arr[i]; i++) {
        if (my_strcmp(arr[i], "set") == 0 && i == 0)
            return;
        if (my_strcmp(arr[i], "$?") == 0)
            continue;
        c = where_to_glob(arr[i]);
        if (c == 0)
            continue;
        update_cmd(tmp, arr[i]);
    }
}

int handle_globing(__attribute__((unused))shell_t *shell, parser_t *cpy)
{
    command_t *tmp = cpy->command;

    if (!tmp)
        return 84;
    for (; tmp; tmp = tmp->prev)
        hold_globing_in_cmd(tmp);
    return 0;
}
