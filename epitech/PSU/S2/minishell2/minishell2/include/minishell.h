/*
** EPITECH PROJECT, 2024
** minishell.h
** File description:
** minishell
*/

#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>


#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define RED "\033[31m"
    #define BOLD "\033[1m"
    #define RES "\033[0m"

typedef struct list_s {
    char *command;
    char **args;
    int ispipe;
    int redirect;
    struct list_s *next;
} list_t;

typedef struct env_s {
    char **tab;
    char **multi;
} env_t;

int shell(env_t *my_env, list_t *multi);
char *command_input(env_t *my_env, char *command, int *value, list_t *multi);
void print_env(env_t *my_env);
int count_args(char *command);
char **handle_args(char *command, char **args);
int add_args(char ***args, char *command);
int basic_tests(char *command, char **args, env_t *my_env, int *value);
char *test_all_env(char *command, char **args, env_t *my_env);
char **path_to_array(char *env, char **path);
int setenvironment(char **args, env_t *my_env);
void add_to_environment(char *name, char *value, env_t *my_env);
char **copy_env(char **env);
int count_line(char **env);
void rm_to_environment(char *name, env_t *my_env);
int unsetenvironment(char **args, env_t *my_env);
void handle_segfault(int result, int *value);
char *research_env(char *research, env_t *my_env);
int change_environment(char *research, char *value, env_t *my_env);
void cut_multi_command(env_t *my_env, char *command, list_t **multi);
int handle_pipe(list_t *multi, char **args, env_t *my_env, int *iterate);
void remove_first_space(char **command);
int handle_redirection(list_t *multi, char **args, env_t *my_env,
    int *iterate);

#endif /* !MINISHELL_H_ */
