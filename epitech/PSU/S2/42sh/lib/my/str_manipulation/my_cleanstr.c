/*
** EPITECH PROJECT, 2024
** my_cleanstr
** File description:
** clean a string
*/

#include "../include/my.h"

int isasep(char c, char *sep)
{
    for (int i = 0; sep[i]; i++)
        if (c == sep[i])
            return 1;
    return 0;
}

long unsigned int count_sep(char *str, char *sep)
{
    long unsigned int cnt = 0;

    for (int i = 0; str && str[i]; i++) {
        if (isasep(str[i], sep) && str[i + 1] && !isasep(str[i + 1], sep))
            cnt++;
        if (!isasep(str[i], sep))
            cnt++;
    }
    return cnt;
}

char *cpy_clean(char *new, char *str, char *sep)
{
    int n_pos = 0;

    for (int i = 0; str[i]; i++) {
        if (isasep(str[i], sep) && str[i + 1] &&
        !isasep(str[i + 1], sep) && n_pos) {
            new[n_pos] = ' ';
            n_pos++;
        }
        if (!isasep(str[i], sep)) {
            new[n_pos] = str[i];
            n_pos++;
        }
    }
    new[n_pos] = '\0';
    return new;
}

char *my_cleanstr(char *str, char *sep)
{
    long unsigned int mal_size = 0;
    char *new = NULL;

    if (!str)
        return NULL;
    for (int i = 0; str && str[i] && isasep(str[i], sep); i++)
        str += 1;
    mal_size = count_sep(str, sep);
    new = my_alloc_str((int)mal_size);
    if (new == NULL)
        return NULL;
    new = cpy_clean(new, str, sep);
    return new;
}
