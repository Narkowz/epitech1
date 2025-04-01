/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** usage
*/

#include "main.h"

#ifndef USAGE_H_
    #define USAGE_H_

char *get_hour(void);
void reset_std(void);
void handler(int signum);
shell_t *get_shell(void);
void prompt(shell_t *shell);
int hold_parsing(shell_t *shell);
void parse_command(parser_t *parser);
void move_cursor(int add, int *index);
char *my_cleanstr(char *str, char *sep);
void glob_error(char *copy, char *message);
char *my_strncat(char *s1, char *s2, int n);
char **simple_str_to_array(char *str, char c);
char *search_path(char **env, char *link_path);

#endif
