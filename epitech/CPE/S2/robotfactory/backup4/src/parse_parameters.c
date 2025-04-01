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
        if (array[i][*l] != ' ' || array[i][*l] != '\t' || array[i][*l] != ',')
            return 0;
    return 1;
}

char **search_parameters(char **array, robot_t *robot)
{
    int i = robot->index;
    int l = 0;
    char **clean = NULL;

    for (; array[i] != NULL; i++) {
        l = 0;
        if (search_parameters_bis(array, clean, i, &l) == 0)
            break;
    }
    if (i < count_line(array)) {
        robot->index = i;
        clean = my_str_bis(array[i], clean);
    } else
        return NULL;
    return clean;
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

int coding_byte(char **clean, robot_t *robot)
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

static char *set_hello(int *value, char **clean, int index, char *hello)
{
    *value = my_getnbr(clean[index]);
    // printf("'%d'\n", *value);
    hello = int_to_char(*value);
    hello = char_to_int(hello);
}

static int search_function(char **clean, int index, int value, robot_t *robot)
{
    char *hello = NULL;
    char temp[10];
    int j = 0;

    if (clean[index][1] == ':') {
        robot->function = malloc(sizeof(char) * my_strlen(clean[index]));
        for (int i = 2; clean[index][i] != '\0'; i++) {
            robot->function[j] = clean[index][i];
            j++;
        }
        robot->function[j] = '\0';
    } else {
        hello = set_hello(&value, clean, index, hello);
        for (int k = 0; k <= count_length(value); k++) {
            temp[k] = hello[k];
            // printf("%d", temp[k]);
        }
        // printf("\n");
        fwrite(&temp, 4, 1, robot->file);
        return 1;
    }
    return 0;
}

static int interpret_param(char **clean, int index, robot_t *robot)
{
    int value;

    if (clean[index][0] == 'r') {
        value = my_getnbr(clean[index]);
        fwrite(&value, 1, 1, robot->file);
        return 1;
    } else if (clean[index][0] == '%') {
        search_function(clean, index, value, robot);
        return 10;
    } else {
        value = my_getnbr(clean[index]);
        reverse_bytes(&value);
        fwrite(&value, 2, 1, robot->file);
        return 11;
    }
}

static int print_args(char **clean, robot_t *robot)
{
    int i = 1;

    for (; clean[i] != NULL; i++) {
        interpret_param(clean, i, robot);
    }
    return 0;
}

static void search_line(char **array, robot_t *robot)
{
    int k = robot->index + 1;
    int l = 0;

    for (; array[k] != NULL; k++) {
        l = 0;
        for (;array[k][l] != '\0'; l++)
            if (array[k][l] != ' ' && array[k][l] != ',' && array[k][l] != '\t') {
                robot->index = k;
                return;
            }
    }
}

static void exchange_order(char ***clean)
{
    int i = 1;

    for (; (*clean)[i] != NULL; i++) {
        (*clean)[i - 1] = my_strdup((*clean)[i]);
    }
    (*clean)[i] = NULL;
}

int parse_parameters(char **array, robot_t *robot)
{
    char **clean = NULL;
    int i = 0;
    FILE *file;
    int byte;
    robot->value = 0;

    for (int k = robot->index + 1; k < count_line(array); k = robot->index) {
        robot->index += 1;
        clean = search_parameters(array, robot);
        for (i = 0; op_tab[i].mnemonique != NULL; i++) {
            // if (robot->value == 0 && robot->function && my_strcmp(clean[0], robot->function) == 0) {
            //     exchange_order(&clean);
            //     robot->value = 1;
            // }
            if (clean && my_strcmp(clean[0], op_tab[i].mnemonique) == 0)
                break;
        }
        if (i != 16) {
            fwrite(&op_tab[i].code, 1, 1, robot->file);
            byte = coding_byte(clean, robot);
            fwrite(&byte, 1, 1, robot->file);
            print_args(clean, robot);
            // if (robot->value == 0)
            //     add_word_to_string(robot->function, ":", &robot->function, NULL);
        }
    }
    return 0;
}
