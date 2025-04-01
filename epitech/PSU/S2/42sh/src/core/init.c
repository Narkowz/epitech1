/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** init
*/

#include "shell.h"
#include "usage.h"
#include "builtin.h"
#include <stdlib.h>
#include <unistd.h>

void init_special_var(shell_t *shell)
{
    char *cwd = malloc((size_t)sizeof(char) * 1024);

    cwd = getcwd(cwd, 1024);
    add_to_var(shell, "cwd", cwd);
    add_to_var(shell, "dirstack", cwd);
    add_to_var(shell, "home", search_path(shell->env, "HOME="));
    add_to_var(shell, "shell", "./42sh");
    add_to_var(shell, "term", "xterm-256color");
}

/**
 * @brief Put Empty variable in each of the shell_t param
 * @param shell_t* the address of the shell
 * @return The address of the shell_t structure
 */
shell_t *init_shell(shell_t *shell, char **env, int open_rc)
{
    shell->parser = NULL;
    shell->save = malloc(sizeof(save_t));
    shell->actual_save = NULL;
    shell->save->input = NULL;
    shell->save->next = NULL;
    shell->save->prec = NULL;
    shell->alias = NULL;
    shell->var = NULL;
    shell->env = env;
    shell->ret = 0;
    shell->open_rc = open_rc;
    shell->nb_tab = 0;
    if (open_rc)
        get_alias(shell);
    init_special_var(shell);
    return shell;
}
