/*
** EPITECH PROJECT, 2024
** parse_parameters.c
** File description:
** parse_parameters
*/

#include "../include/robotfactory.h"

int search_parameters_bis(char **array, char **clean, int i, int *l)
{
    for (; array[i][*l] != '\0'; (*l)++)
        if (array[i][*l] != ' ' || array[i][*l] != '\t')
            return 0;
    return 1;
}

char **search_parameters(char **array, robot_t *robot)
{
    int i = robot->index + 1;
    int l = 0;
    char **clean = NULL;

    for (; array[i] != NULL; i++) {
        l = 0;
        if (search_parameters_bis(array, clean, i, &l) == 0)
            break;
    }
    clean = my_str_bis(array[i], clean);
}

int search_coding_byte(char **clean, int index)
{
    if (clean[index][0] == 'r')
        return 1;
    else if (clean[index][0] == '%')
        return 10;
    else
        return 11;
}

int coding_byte(char **clean, int index, robot_t *robot)
{
    int i = 2;
    char *byte = int_to_char(search_coding_byte(clean, 1));
    int value;

    for (; clean[i] != NULL; i++) {
        add_word_to_string(byte, int_to_char(search_coding_byte(clean, i)),
            &byte, NULL);
    }
    return binary_to_int(byte);
}

static int print_args(char **clean, int index, robot_t *robot)
{
    return 0;
}

int parse_parameters(char **array, robot_t *robot)
{
    char **clean = search_parameters(array, robot);
    int i = 0;
    FILE *file;
    int byte;

    for (; op_tab[i].mnemonique != NULL; i++)
        if (my_strcmp(clean[0], op_tab[i].mnemonique) == 0)
            break;
    if (i != 16) {
        fwrite(&op_tab[i].code, 1, 1, robot->file);
        byte = coding_byte(clean, i, robot);
        fwrite(&byte, 1, 1, robot->file);
        print_args(clean, i, robot);
        return 0;
    }
    return 84;
}
