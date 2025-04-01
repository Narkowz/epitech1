/*
** EPITECH PROJECT, 2023
** Lingo
** File description:
** lingo.h
*/

#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

#ifndef LINGO_H_
    #define LINGO_H_
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
char *opening_file(char *path);
char **my_str_to_word_array(char *path, char **env);
void print_header(void);
int game_loop(char *result, char *word);

#endif
