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

void print_usage(void);
int test_file(char *file);
int open_file(char *path, char **content);
int translate_to_cor(char *cont, header_t *content, char **array, char *name);
int test_content(char **array);
void add_to_file(header_t *content, char *name);
int clean_line(char *cont);
int count_line(char **env);
char **my_str_bis(char *env, char **path);
#endif /* !ROBOTFACTORY_H_ */
