/*
** EPITECH PROJECT, 2024
** basic_tests_command.c
** File description:
** basic_tests_command
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

int execute_oldpwd(char ***args, env_t *my_env, struct stat *sa)
{
    char *oldpwd = NULL;

    if ((*args)[1][0] == '-') {
        oldpwd = research_env("OLDPWD", my_env);
        if (oldpwd != NULL) {
            free((*args)[1]);
            (*args)[1] = my_strdup(oldpwd);
        } else {
            (*args)[1] = my_strdup("");
            return 1;
        }
        stat((*args)[1], sa);
        return 0;
    }
    return 1;
}

int change_environment(char *research, char *value, env_t *my_env)
{
    int i = 0;
    int len = my_strlen(research);
    int count = 0;

    for (; my_env->tab[i] != NULL; i++)
        if (my_strncmp(research, my_env->tab[i], len, 0) == len) {
            count++;
            break;
        }
    if (count == 0)
        return 1;
    add_word_to_string(research, value, &my_env->tab[i], "=");
}

int execute_cd(struct stat *sa, char *command, char **args, env_t *my_env)
{
    if (S_ISREG(sa->st_mode)) {
        mini_printf(RED BOLD "%s: Not a directory.\n", args[1], RES);
        return 1;
    }
    if (S_ISDIR(sa->st_mode)) {
        change_environment("OLDPWD", getcwd(NULL, 0), my_env);
        chdir(args[1]);
        change_environment("PWD", getcwd(NULL, 0), my_env);
        return 0;
    }
}

static void cd_home(env_t *my_env)
{
    change_environment("OLDPWD", getcwd(NULL, 0), my_env);
    chdir(research_env("HOME", my_env));
    change_environment("PWD", getcwd(NULL, 0), my_env);
}

int test_cd(char *command, char **args, env_t *my_env, int *value)
{
    int result;
    struct stat sa;

    if (count_line(args) > 2) {
        mini_printf(RED BOLD "%s: Too many arguments.\n", command);
        *value = 1;
        return 0;
    }
    if (args[1]) {
        result = stat(args[1], &sa);
        if (result == 0 || execute_oldpwd(&args, my_env, &sa) == 0)
            *value = execute_cd(&sa, command, args, my_env);
        else {
            mini_printf(RED BOLD "%s: No such file or directory.\n",
                args[1], RES);
            *value = 1;
        }
    } else
        cd_home(my_env);
    return 0;
}

int basic_tests(char *command, char **args, env_t *my_env, int *value)
{
    if (command[0] == '\0' || command[0] == ' ')
        return 0;
    if (my_strcmp("exit", command) == 0)
        return 0;
    if (my_strcmp("env", command) == 0) {
        print_env(my_env);
        return 0;
    }
    if (my_strncmp("cd", command, 2, 0) == 2) {
        test_cd(command, args, my_env, value);
        return 0;
    }
    return -1;
}
