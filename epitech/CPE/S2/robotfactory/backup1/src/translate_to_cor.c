/*
** EPITECH PROJECT, 2024
** translate_to_cor.c
** File description:
** translate_to_cor
*/

#include "../include/robotfactory.h"

int count_line(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++);
    return i;
}

static int count_char(char *cont, int i)
{
    for (i += 1; cont[i] != '"'; i++);
    return i;
}

int just_a_for(char **array, int l, int *i)
{
    for (; array[l][*i] != '\0'; (*i)++) {
        if (array[l][*i] == '"') {
            return 1;
        }
    }
    return 0;
}

void get_name(char **array, header_t *content)
{
    int i = 0;
    int k = 0;
    int l = 0;

    for (; array[l] != NULL; l++) {
        i = 0;
        if (just_a_for(array, l, &i) == 1)
            break;
    }
    for (i += 1; array[l][i] != '"'; i++) {
        content->prog_name[k] = array[l][i];
        k++;
    }
    content->prog_name[k] = '\0';
    return;
}

void get_comment(char **array, header_t *content)
{
    int i = 0;
    int k = 0;
    int l = 0;
    int count = -1;
    int len = my_strlen(".comment");

    for (; array[i] != NULL; i++)
        if (my_strncmp(".comment", array[i], len, clean_line(array[i])) == len)
            break;
    if (i != count_line(array)) {
        just_a_for(array, i, &l);
        for (l += 1; array[i][l] != '"'; l++) {
            content->comment[k] = array[i][l];
            k++;
        }
        content->comment[k] = '\0';
    }
    return;
}

int translate_to_cor(char *cont, header_t *content, char **array, char *name)
{
    char **path = NULL;

    content->magic = COREWAR_EXEC_MAGIC;
    get_name(array, content);
    get_comment(array, content);
    path = my_str_bis(array[10], path);
    for (int i = 0; path[i] != NULL; i++)
        printf("'%s'\n", path[i]);
    add_to_file(content, name);
}
