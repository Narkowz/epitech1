/*
** EPITECH PROJECT, 2024
** command_input.c
** File description:
** command_input
*/

#include "include/minishell.h"
#include "include/my.h"

int number_args(char *command)
{
    int count = 0;
    int i = 0;

    for (; command[i] != '\0'; i++)
        if (command[i] == ' ')
            count++;
    return count;
}

void test_arguments(char *command, char ***args)
{
    int i = 0;
    char *token = NULL;

    token = strtok(command, " ");
    while (token != NULL) {
        token = strtok(NULL, " ");
        (*args)[i] = token;
        i++;
    }
    (*args)[i] = NULL;
    free(token);
}

int lunch_process(char *command, char **args, char **env)
{
    pid_t p = fork();

    if (p == 0) {
        execve(command, NULL, NULL);
        printf("test '%s'\n", command);
        perror("execve");
        exit(EXIT_FAILURE);
    } else
        waitpid(p, 0, 0);
}

int test_command(char *command, char **args, char **env)
{
    struct stat sa;

    if (my_strcmp("exit", command) == 0)
        return 0;
    if (my_strcmp("env", command) == 0) {
        print_env(env);
        return 0;
    }
    if (my_strncmp("/bin/", command, 5) != 5)
        add_word_to_string("/bin/", command, &command);
    // lunch_process(command, args, env);
    if (stat(command, &sa) == 0) {
        lunch_process(command, args, env);
        return 0;
    }
}

char *command_input(char **env)
{
    char *command = NULL;
    char **args = NULL;
    size_t size = 0;
    ssize_t read = 0;
    int nb_args = 0;

    read = getline(&command, &size, stdin);
    command[my_strlen(command) - 1] = '\0';
    nb_args = number_args(command);
    printf("nb %d\n", nb_args);
    if (nb_args != 0) {
        args = malloc(sizeof(char *) * (nb_args + 1));
        test_arguments(command, &args);
        printf("%s\n", args[0]);
    }
    if (test_command(command, args, env) != 0)
        // mini_printf("command not found...\n");
    // for (int i = 0; i <= nb_args + 1; i++)
    //     free(args[i]);
    // free(args);
    return command;
}
