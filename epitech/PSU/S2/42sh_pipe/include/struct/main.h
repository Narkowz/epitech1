/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#ifndef MAIN_H_
    #define MAIN_H_

typedef enum separator_e {
    T_OTHER,
    T_PIPE,
    T_DRRIGHT,
    T_DRLEFT,
    T_RRIGHT,
    T_RLEFT,
    T_SEMICOLON,
    T_QUOTE,
    T_LPARENTHESIS,
    T_RPARENTHESIS,
    T_SINGLE_QUOTE,
    NB_SEP,
    T_EOF
} separator_t;

typedef struct command_s {
    separator_t sep;
    char *cmd;
    char **arr;
    struct command_s *prev;
    struct command_s *next;
} command_t;

typedef struct parser_s {
    char *input;
    char **separators;
    command_t *command;
} parser_t;

typedef struct save_s {
    char *input;
    char *time;
    struct save_s *next;
    struct save_s *prec;
} save_t;

typedef struct alias_s {
    char *initial;
    char *result;
    struct alias_s *next;
} alias_t;

typedef struct shell_s {
    char **env;
    save_t *save;
    alias_t *alias;
    int ret;
    parser_t *parser;
} shell_t;

#endif
