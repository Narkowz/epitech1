/*
** EPITECH PROJECT, 2024
** robotfactory.h
** File description:
** robotfactory
*/

#ifndef ROBOTFACTORY_H_
    #define ROBOTFACTORY_H_
    #include "op.h"
    #include "my.h"
    #include "my_printf.h"
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/fcntl.h>

typedef struct robot_s {
    int index;
    FILE *file;
} robot_t;

void print_usage(void);
int test_file(char *file);
int count_line(char **env);
int clean_line(char *cont);
int binary_to_int(char *arg);
int find_com(char *str, int j);
int test_content(char **array);
char **my_str_bis(char *env, char **path);
int open_file(char *path, char **content);
int parse_parameters(char **array, robot_t *robot);
void add_to_file(header_t *content, char *name, robot_t *robot);
int translate_to_cor(char *cont, header_t *content, char **array, char *name);
#endif /* !ROBOTFACTORY_H_ */
