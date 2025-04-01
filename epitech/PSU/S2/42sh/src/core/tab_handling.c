/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** tab_handling.c
*/

#include "shell.h"
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include <glob.h>

static char *rp_last(char *ori, char *new, char *last)
{
    char *temp = my_strdup(ori);
    int last_i = 0;
    int dif = my_strlen(new) - my_strlen(last);
    int len = my_strlen(ori);

    for (int i = 0; ori[i] && i < len - my_strlen(last); i++) {
        temp++;
        if (strncmp(temp, last, (size_t)my_strlen(last)) == 0)
            last_i = i;
    }
    temp = NULL;
    temp = my_alloc_str(len + dif);
    temp = strncpy(temp, ori, (size_t)(last_i + 1));
    if (last_i == 0)
        for (int i = last_i + 1; i < last_i + my_strlen(new); i++)
            temp[i] = new[i - last_i];
    else
        for (int i = last_i; i < last_i + my_strlen(new); i++)
            temp[i + 1] = new[i - last_i];
    return temp;
}

static char *add_star(char **arr, char **last)
{
    char *temp = NULL;
    int i = 0;

    if (!arr || my_tab_len(arr) == 0)
        return NULL;
    (*last) = my_strdup(arr[my_tab_len(arr) - 1]);
    if (!last || !(*last))
        return NULL;
    temp = my_alloc_str(my_strlen((*last)) + 1);
    for (i = 0; (*last)[i]; i++)
        temp[i] = (*last)[i];
    temp[i] = '*';
    return temp;
}

static void display_all_tab(char **arr, shell_t *shell, int *index)
{
    prompt_exe(shell->save->input);
    for (int i = 0; arr && arr[i]; i++) {
        printf("%s", arr[i]);
        if (arr[i + 1] && (i + 1) % 5 != 0)
            printf("\t");
        if (arr[i + 1] && (i + 1) % 5 == 0)
            printf("\n");
    }
    printf("\n");
    reset_and_move_back(shell, index);
    fflush(stdout);
}

static int check_one_conflict(int i, char **arr)
{
    for (int y = 1; arr[y]; y++)
        if (i >= my_strlen(arr[y]) || arr[y][i] != arr[0][i])
            return 84;
    return 0;
}

static void go_to_conflict(char **arr, shell_t *shell, int *index, char *last)
{
    int i = 0;
    char *new = NULL;

    if (!arr || !arr[0])
        return;
    for (i = 0; arr[0][i]; i++) {
        if (check_one_conflict(i, arr) == 84)
            break;
    }
    new = my_alloc_str(i);
    new = strncpy(new, arr[0], (size_t)i);
    shell->save->input = rp_last(shell->save->input,
            new, last);
    reset_and_move_back(shell, index);
}

static void handle_single_path(glob_t info, shell_t *shell, int *index,
    char *last)
{
    DIR *dir;

    dir = opendir(info.gl_pathv[0]);
    if (dir)
        info.gl_pathv[0] = add_char(info.gl_pathv[0],
            my_strlen(info.gl_pathv[0]), '/');
    shell->save->input = rp_last(shell->save->input,
        info.gl_pathv[0], last);
    closedir(dir);
    reset_and_move_back(shell, index);
}

void handle_tab(shell_t *shell, int *index)
{
    glob_t info = {0};
    char **cmd_arr = my_str_to_word_array(shell->save->input);
    char *last = NULL;
    char *temp = add_star(cmd_arr, &last);

    shell->nb_tab += 1;
    glob(temp, 0, NULL, &info);
    if (!info.gl_pathv)
        return;
    if (info.gl_pathc == 1)
        handle_single_path(info, shell, index, last);
    if (shell->nb_tab == 1 && info.gl_pathc > 1)
        go_to_conflict(info.gl_pathv, shell, index, last);
    if (shell->nb_tab >= 2 && info.gl_pathc > 1)
        display_all_tab(info.gl_pathv, shell, index);
}
