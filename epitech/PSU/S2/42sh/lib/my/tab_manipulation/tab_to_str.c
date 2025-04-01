/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** tab_to_str.c
*/

#include "my.h"

char *tab_to_str(char **tab)
{
    char *result = NULL;
    int index = 0;
    int len = 0;

    for (int i = 0; tab && tab[i]; i++)
        len += my_strlen(tab[i]) + 1;
    result = my_alloc_str(len);
    for (int i = 0; tab && tab[i]; i++) {
        for (int y = 0; tab[i][y]; y++) {
            result[index] = tab[i][y];
            index++;
        }
        result[index] = ' ';
        index++;
    }
    return result;
}
