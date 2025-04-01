/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** handle_redirections.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

void execution(char **args, env_t *my_env)
{
    pid_t pid = fork();
    int res;
    struct stat sa;

    if (pid == 0) {
        if (stat(args[0], &sa) != 0)
            args[0] = test_all_env(args[0], args, my_env);
        if (args[0] != NULL) {
            execve(args[0], args, (char *const *) NULL);
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else
        waitpid(pid, &res, 0);
}

void redirect_to_file(char *command, char **args, env_t *my_env, int *iterate)
{
    int fd;
    static int original_stdout = -1;
    char *file_path = args[count_args(command)];

    if (original_stdout == -1)
        original_stdout = dup(STDOUT_FILENO);
    if (my_strstr(command, ">>") == NULL)
        fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    else
        fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    for (int i = 0; args[i] != NULL; i++)
        if (my_strstr(args[i], ">") != NULL)
            args[i] = NULL;
    execution(args, my_env);
    dup2(original_stdout, STDOUT_FILENO);
    close(fd);
}

void redirect_in_comm(char *command, char **args, env_t *my_env)
{
    int fd;
    static int original_stin = -1;
    char *file_path = args[count_args(command)];

    if (original_stin == -1)
        original_stin = dup(STDIN_FILENO);
    fd = open(file_path, O_RDONLY, S_IRWXU);
    dup2(fd, STDIN_FILENO);
    close(fd);
    for (int i = 0; args[i] != NULL; i++)
        if (my_strstr(args[i], "<") != NULL)
            args[i] = NULL;
    execution(args, my_env);
    dup2(original_stin, STDIN_FILENO);
    close(fd);
}

static void getline_loop(int fd, char *end, char *cmd)
{
    size_t size;

    while (1) {
        if (isatty(0))
            write(1, "? ", 2);
        getline(&cmd, &size, stdin);
        cmd[my_strlen(cmd) - 1] = '\0';
        if (my_strcmp(cmd, end) != 0) {
            write(fd, cmd, my_strlen(cmd));
            write(fd, "\n", 1);
        } else
            return;
    }
}

static void double_redirection(char *command, char **args, env_t *my_env)
{
    int fd;
    char *cmd = NULL;
    static int original_stin = -1;

    if (original_stin == -1)
        original_stin = dup(STDIN_FILENO);
    fd = open("tmp/temp_db_redirect", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    getline_loop(fd, args[count_line(args) - 1], cmd);
    close(fd);
    add_word_to_string(args[0], "tmp/temp_db_redirect", &command, " < ");
    args = my_str_to_word_array(command, args);
    redirect_in_comm(command, args, my_env);
}

static int test_syntax(char **args)
{
    char last = args[count_line(args) - 1]
        [my_strlen(args[count_line(args) - 1]) - 1];

    if (last == '<' || last == '>') {
            my_putstr(RED, 2);
            my_putstr(BOLD, 2);
            my_putstr("Missing name for redirect.\n", 2);
            my_putstr(RES, 2);
            return 84;
    }
    if (my_strstr(args[count_line(args) - 1], "<") != NULL ||
        my_strstr(args[count_line(args) - 1], ">") != NULL) {
            my_putstr(RED, 2);
            my_putstr(BOLD, 2);
            my_putstr("Ambigus input redirect.\n", 2);
            my_putstr(RES, 2);
            return 84;
    }
}

int handle_redirection(list_t *multi, char **args, env_t *my_env, int *iterate)
{
    int nb_cmds;
    char ***cmds = NULL;

    if (!multi || my_strstr(multi->command, ">") == NULL &&
        my_strstr(multi->command, "<") == NULL)
        return 0;
    if (test_syntax(args) == 84)
        return 84;
    if (my_strstr(multi->command, ">") != NULL)
        redirect_to_file(multi->command, args, my_env, iterate);
    else if (my_strstr(multi->command, "<<") != NULL)
        double_redirection(multi->command, args, my_env);
    else
        redirect_in_comm(multi->command, args, my_env);
    (*iterate)++;
    return 1;
}
