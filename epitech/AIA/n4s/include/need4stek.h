/*
** EPITECH PROJECT, 2024
** need4stek
** File description:
** need4stek
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef NEED4STEK_H_
    #define NEED4STEK_H_
    #define RED "\033[31m"
    #define BOLD "\033[1m"
    #define RES "\033[0m"
    #define GREEN "\033[0;32m"

typedef struct all_s {
    char **coo_lidar;
    char *buf;
    float middle;
    int average;
    float angle;
    int lap;
} all_t;

char **my_str_to_word_array(char *env, char **path);
int my_getnbr(char *av);
int count_lines(char **args);
int add_word_to_string(char *source, char *word, char **result, char *between);
char *my_get_str(float number);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strdup(char const *src);

int count_lines(char **args);
void handling_turn(size_t size, all_t *all);

void do_turn_2(all_t *all, size_t size);
void do_turn_3(all_t *all, size_t size);
void do_turn(all_t *all, size_t size);
void do_turn_big(all_t *all, size_t size);
void end_simu(all_t *all, size_t size);
int write_ev(all_t *all, size_t size, char *str);

#endif /* !NEED4STEK_H_ */
