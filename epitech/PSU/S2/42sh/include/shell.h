/*
** EPITECH PROJECT, 2024
** Minigashell
** File description:
** minishell
*/

#include "main.h"

#ifndef MINISHELL_H_
    #define MINISHELL_H_

int shell(char **env, int open_rc);
int get_original_stdin(void);
int get_original_stdout(void);
shell_t *init_shell(shell_t *shell, char **env, int open_rc);

void prompt(shell_t *shell);
void prompt_exe(char *input);
void ctrl_d(shell_t *shell);
void exit_minishell(shell_t *shell);

void disable_raw_mode(void);
void enable_raw_mode(void);
void reset_command(char *input);
void move_back_cursor(char *input, int index);
void reset_and_move_back(shell_t *shell, int *index);

int get_input(shell_t *shell);
void handle_tab(shell_t *shell, int *index);
void analyse_line(char *line, shell_t *shell);
void search_in_history(shell_t *shell, int *index);

int verif_before_exec(shell_t *shell);
void execute_all_commands(shell_t *shell);
void execute_one_command(shell_t *shell);
command_t *handle_redirect(shell_t *shell, command_t *cmd);
command_t *handle_paranthesis(shell_t *shell, command_t *command);
command_t *handle_quote(shell_t *shell, command_t *command, int reset);
command_t *handle_rright_or_drright(shell_t *shell, command_t *cpy, int index);
command_t *handle_rleft_or_drleft(shell_t *shell, command_t *cpy, int index);
command_t *handle_and(shell_t *shell, command_t *command);
command_t *handle_or(shell_t *shell, command_t *command);
void read_until(char *end_name, int tmp_fd);
int open_redirect(int sep, char *filename);
command_t *handle_pipe(shell_t *shell, command_t *command);

char *get_command(char **env, char *bin);
int handle_globing(__attribute__((unused))shell_t *shell, parser_t *cpy);

void save_command(shell_t *shell);
void handle_arrow(char c, int *index, shell_t *shell);

void free_shell(shell_t *shell);
void free_shell_contain(shell_t *shell);

//Error
void invalid_command(command_t *command, shell_t *shell);
void err_exec(char *copy, char *message);
#endif
