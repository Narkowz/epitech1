/*
** EPITECH PROJECT, 2024
** test_position.c
** File description:
** test_position
*/

#include "include/my.h"
#include "include/my_navy.h"

extern global_t global;

int send_another_signal(void)
{
    if (global.sig2 == 2 && global.sig1 == 0 && global.player_turn == 0)
        global.first->last_shoot == 1;
    if (global.sig2 == 2 && global.sig1 == 0 && global.player_turn == 1)
        global.second->last_shoot == 1;
    if (global.sig2 == 3 && global.sig1 == 0 && global.player_turn == 0)
        global.first->last_shoot == -1;
    if (global.sig2 == 3 && global.sig1 == 0 && global.player_turn == 1)
        global.second->last_shoot == -1;
}

int test_position(void)
{
    if (global.player_turn == 0) {
        //player 2
        printf("iciccc %s\n", global.second->my_map[global.message[1] - 49 + 2]);
        printf("laaaaa '%c'\n", global.second->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2]);
        if (global.second->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2] != '.') {
            kill(global.my_pid, SIGUSR2);
            usleep(4000);
            kill(global.my_pid, SIGUSR2);
            global.first->last_shoot = 1;
        } else {
            kill(global.opponent_pid, SIGUSR2);
            usleep(4000);
            kill(global.opponent_pid, SIGUSR2);
            usleep(4000);
            kill(global.opponent_pid, SIGUSR2);
            global.first->last_shoot = -1;
        }
        printf("resultaaaat : '%d'\n", global.first->last_shoot);
    } else {
        printf("iciccc %s\n", global.first->my_map[global.message[1] - 49 + 2]);
        printf("laaaaa '%c'\n", global.first->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2]);
        if (global.first->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2] != '.')
            global.second->last_shoot = 1;
        else
            global.second->last_shoot = -1;
        printf("resultaaaat : '%d'\n", global.second->last_shoot);
    }
}
