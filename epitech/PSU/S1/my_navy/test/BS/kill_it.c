/*
** EPITECH PROJECT, 2024
** kill_it.c
** File description:
** kill_it
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int get_nbr(char *av)
{
    int number = 0;
    int i = 0;

    while (av[i] != '\0') {
        number = number * 10 + (av[i] - '0');
        i++;
    }
    return number;
}

int main(int argc, char **argv)
{
    int id;
    pid_t pid;

    if (argc == 2) {
        id = get_nbr(argv[1]);
        pid = id;
        kill(pid, SIGQUIT);
        printf("%i\n", pid);
        return 0;
    }
    return 84;
}
