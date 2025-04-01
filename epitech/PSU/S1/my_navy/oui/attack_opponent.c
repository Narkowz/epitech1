/*
** EPITECH PROJECT, 2024
** attach_opponent.c
** File description:
** attack_opponent
*/

#include "include/my.h"
#include "include/my_navy.h"



int attack_opponent(pid_t opponent_pid, int *msg)
{
    int i = 0;

    for (; msg[i] != -1; i++) {
        if (msg[i] == 0)
            kill(opponent_pid, SIGUSR1);
        if (msg[i] == 1)
            kill(opponent_pid, SIGUSR2);
    }
    return 0;
}
