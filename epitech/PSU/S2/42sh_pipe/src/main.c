/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** main
*/

#include <sys/wait.h>
#include "shell.h"

/**
 * @brief Main function, i think it's useless to explain this one
 * @param int the number of arguments
 * @param char** the arguments in each char *
 * @param char** The env Variable of the computer
 * @returns int: The value of the 42sh
 */
int main(int argc, char **argv, char **env)
{
    int value = 0;
    char *args[] = {"/bin/bash", "script/.42shrc", NULL};

    if (fork() == 0)
        execve("/bin/bash", args, NULL);
    else
        wait(&value);
    if (argc != 1 && argv)
        return 84;
    get_original_stdout();
    enable_raw_mode();
    value = shell(env);
    disable_raw_mode();
    return value;
}
