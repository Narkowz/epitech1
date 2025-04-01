/*
** EPITECH PROJECT, 2024
** my_navy.h
** File description:
** my_navy
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_

    typedef struct first_s {
        char **my_map;
        char **enemy_map;
        int is_running;
    } first_t;

    typedef struct second_s {
        char **my_map;
        char **enemy_map;
        int is_runnig;
    } second_t;

void print_usage(void);
int testing_file(char *path);
char *int_to_binary(char arg);
int binary_to_int(char *arg);

#endif /* !MY_NAVY_H_ */
