/*
** EPITECH PROJECT, 2024
** my_navy.c
** File description:
** uwu
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/my_navy.h"

global_t global;

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

void handle_signal(int sig_no)
{
    if (sig_no == SIGUSR1) {
        global.is_running = 1;
    }
}

int exe_player1(char *path, first_t *navy)
{
    pid_t pid_joueur1 = getpid();
    int i = 0;

    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    printf("my_pid: %d\n\n", pid_joueur1);
    signal(SIGUSR1, handle_signal);
    printf("waiting for enemy connection...\n\n");
    while (!global.is_running)
        usleep(100000);
    printf("enemy connected\n\n");
    navy->my_map = read_file(path, navy->my_map);
    printf("my navy:\n");
    for (; i < 10; i++)
        printf("%s\n", navy->my_map[i]);
    printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        printf("%s\n", navy->enemy_map[k]);
}

int exe_player2(pid_t pid_player1, char *argument, second_t *navy)
{
    pid_t pid = getpid();
    int i = 0;

    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    printf("my_pid: %d\n\n", pid, pid_player1);
    usleep(100000);
    if (kill(pid_player1, SIGUSR1) == -1) {
        printf("Erreur\n");
        return (84);
    }
    printf("successfully connected\n");
    navy->my_map = read_file(argument, navy->my_map);
    printf("\nmy navy:\n");
    for (; i < 10; i++)
        printf("%s\n", navy->my_map[i]);
    printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        printf("%s\n", navy->enemy_map[k]);
}

int main(int argc, char *argv[])
{
    pid_t pid_joueur;
    first_t *first = malloc(sizeof(first_t));
    second_t *second = malloc(sizeof(second_t));

    global.is_running = 0;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (argc == 2 && test_file(argv[1]) == 0) {
        exe_player1(argv[1], first);
    } else if (test_file(argv[2]) == 0){
        pid_joueur = get_nbr(argv[1]);
        exe_player2(pid_joueur, argv[2], second);
    }
    return 84;
}
