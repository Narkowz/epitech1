/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-titouan.pradoura
** File description:
** simple_str_to_array.c
*/

#include "my.h"

char **simple_str_to_array(char *str, char c)
{
    int cut;
    int count = my_count_char(str, c);
    int count_alone = my_count_char_alone(str, c);
    char *save;
    char **tab;

    if (count != count_alone)
        return NULL;
    tab = my_alloc_tab(count + 1);
    for (int i = 0; i <= count; i++) {
        cut = my_locate_char(str, c);
        if (cut == -1)
            tab[i] = my_strdup(str);
        else {
            tab[i] = my_str_slice(str, 0, cut - 1);
            save = my_str_slice(str, cut + 1, my_strlen(str));
            str = my_strdup(save);
        }
    }
    return tab;
}
