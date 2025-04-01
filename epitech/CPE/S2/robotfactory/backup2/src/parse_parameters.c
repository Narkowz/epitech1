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

void parse_parameters(char **array, robot_t *robot)
{
    char **clean = search_parameters(array, robot);
}
