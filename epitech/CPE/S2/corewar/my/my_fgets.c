/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "my.h"


int read_and_handle_char(char *str, int *i, FILE *stream)
{
    int c = my_fgetc(stream);

    if (c == -1) {
        if (*i == 0)
            return -1;
        else
            return 1;
    } else {
        str[*i] = (char)c;
        (*i)++;
        if (c == '\n')
            return 1;
    }
    return 0;
}

char *my_fgets(char *str, int num, FILE *stream)
{
    int i = 0;
    int result;

    if (str == NULL || num <= 0 || stream == NULL)
        return NULL;
    while (i < num - 1) {
        result = read_and_handle_char(str, &i, stream);
        if (result != 0)
            break;
    }
    str[i] = '\0';
    return (result == -1) ? NULL : str;
}
