/*
** EPITECH PROJECT, 2024
** who_sign_me.c
** File description:
** who_sig_me
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

pid_t kill_it(int argc, char **argv)
{
    int id;
    pid_t pid;

    id = get_nbr(argv[1]);
    pid = id;
    return pid;
}

int main(int argc, char ** argv)
{
    pid_t id = get_id(argv[3]);
    int one = get_nbr(argv[1]);
    int two = get_nbr(argv[2]);
    struct sigaction sig;

    sa.sa_handler = 
    kill(id, one);
    sigaction();
    kill(id, two);
    kill(id, one);
    kill(id, SIGQUIT);
    print("")
}
