/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** mix.h
*/

#include <unistd.h>
#include <stdarg.h>

#ifndef MIX_H_
    #define MIX_H_
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
char *opening_file(char *path);
char **my_str_to_word_array(char *path, char **env);
int my_str_is_num(char const *str);
int gest_error(int ac, char **av);
#endif
