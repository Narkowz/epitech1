/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** builtin
*/

#include "shell.h"

#ifndef BUILTIN_H_
    #define BUILTIN_H_

void my_cd(shell_t *shell);
void my_env(shell_t *shell);
int builtin(shell_t *shell);
void my_set(shell_t *shell);
void my_echo(shell_t *shell);
void my_alias(shell_t *shell);
void get_alias(shell_t *shell);
void my_setenv(shell_t *shell);
void my_history(shell_t *shell);
int apply_alias(shell_t *shell);
void my_unsetenv(shell_t *shell, int index);
void add_to_var(shell_t *shell, char *var_name, char *var_value);

#endif
