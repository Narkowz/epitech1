/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** cd
*/

#include <errno.h>
#include "shell.h"
#include "my.h"

static char *get_pwd(char **env)
{
    for (int i = 0; env[i]; i++)
        if (my_strlen(env[i]) >= 7 && !strncmp(env[i], "PWD=", 4))
            return &env[i][4];
    return NULL;
}

static char *get_home(char **env)
{
    for (int i = 0; env[i]; i++)
        if (my_strlen(env[i]) >= 5 && !strncmp(env[i], "HOME=", 5))
            return &env[i][5];
    return NULL;
}

static char *get_oldpwd(char **env)
{
    for (int i = 0; env[i]; i++)
        if (my_strlen(env[i]) >= 7 && !strncmp(env[i], "OLDPWD=", 7))
            return &env[i][7];
    return NULL;
}

static void change_oldpwd(char ***env)
{
    char olpwd[1024] = "OLDPWD=";

    for (int i = 0; (*env)[i]; i++) {
        if (my_strlen((*env)[i]) >= 7 &&
        !strncmp((*env)[i], "OLDPWD=", 7)) {
            (*env)[i] = my_strdup(my_strcat(olpwd, get_pwd(*env)));
            return;
        }
    }
    append(env, my_strcalloc("OLDPWD=", get_pwd(*env)));
}

static void change_pwd(char ***env)
{
    char newpwd[1024] = "PWD=";
    char pwd[1024];

    for (int i = 0; (*env)[i]; i++) {
        if (my_strlen((*env)[i]) >= 4 && !strncmp((*env)[i], "PWD=", 4)) {
            (*env)[i] = my_strdup(my_strcat(newpwd, getcwd(pwd, 1024)));
            return;
        }
    }
    append(env, my_strcalloc("PWD=", getcwd(pwd, 1024)));
}

static void error_handling(int error, char *command)
{
    if (command)
        my_putstr(command, 2);
    if (error == EACCES)
        my_putstr(": Permission denied.\n", 2);
    if (error == ENOENT)
        my_putstr(": No such file or directory.\n", 2);
    if (error == ENOTDIR)
        my_putstr(": Not a directory.\n", 2);
}

static void cd_back(shell_t *shell)
{
    char *newpwd = get_oldpwd(shell->env);
    int error;

    if (newpwd) {
        error = chdir((const char *)newpwd);
        if (error) {
            error = errno;
            error_handling(error, newpwd);
            shell->ret = 1;
        } else {
            change_oldpwd(&shell->env);
            change_pwd(&shell->env);
            shell->ret = 0;
        }
    } else {
        my_putstr(": No such file or directory.\n", 2);
        shell->ret = 1;
    }
}

static void cd_home(shell_t *shell)
{
    char *home = get_home(shell->env);
    int error;

    if (home) {
        error = chdir((const char *)home);
        if (error) {
            error = errno;
            error_handling(error, home);
            shell->ret = 1;
        } else {
            change_oldpwd(&shell->env);
            change_pwd(&shell->env);
            shell->ret = 0;
        }
    } else {
        my_putstr(": No such file or directory.\n", 2);
        shell->ret = 1;
    }
}

static void cd_path(shell_t *shell)
{
    int error;

    error = chdir((const char *)shell->parser->command->arr[1]);
    if (error) {
        error = errno;
        error_handling(error, shell->parser->command->arr[1]);
        shell->ret = 1;
    } else {
        change_oldpwd(&shell->env);
        change_pwd(&shell->env);
        shell->ret = 0;
    }
}

void my_cd(shell_t *shell)
{
    if (my_tab_len(shell->parser->command->arr) > 2) {
        my_putstr("cd: Too many arguments.\n", 2);
        return;
    }
    if (my_tab_len(shell->parser->command->arr) < 2 ||
    !strcmp(shell->parser->command->arr[1], "~")) {
        cd_home(shell);
        return;
    }
    if (!strcmp(shell->parser->command->arr[1], "-")) {
        cd_back(shell);
        return;
    }
    cd_path(shell);
}
