/*
** EPITECH PROJECT, 2024
** test_position.c
** File description:
** test_position
*/

#include "include/my.h"
#include "include/my_navy.h"

extern global_t global;

void send_another_signal(void)
{
    if (global.sig2 == 2) {
        printf("test shoot '%d'\n", global.first->last_shoot);
        printf("wait\n");
        printf("value '%d'\n", global.sig2);
        usleep(20000);
    }
    if (global.sig2 == 2 && global.sig1 == 0 && global.player_turn == 0) {
        global.first->last_shoot = 1;
        // global.sig2 = 0;
        // global.sig1 = 0;
        printf("touch 1\n");
        return;
    }
    if (global.sig2 == 2 && global.sig1 == 0 && global.player_turn == 1) {
        global.second->last_shoot = 1;
        // global.sig2 = 0;
        // global.sig1 = 0;
        printf("touch 2\n");
        return;
    }
    if (global.sig2 == 3 && global.sig1 == 0 && global.player_turn == 0) {
        printf("miss 1\n");
        global.first->last_shoot = -1;
        // global.sig2 = 0;
        // global.sig1 = 0;
        return;
    }
    if (global.sig2 == 3 && global.sig1 == 0 && global.player_turn == 1) {
        printf("miss 2\n");
        global.second->last_shoot = -1;
        // global.sig2 = 0;
        // global.sig1 = 0;
        return;
    }
    if (global.first->last_shoot != 0 || global.second->last_shoot != 0) {
        printf("je remet a 0\n");
        global.sig2 = 0;
        global.sig1 = 0;
    }
}

int test_position(void)
{
    if (global.player_turn == 0) {
        //player 2
        // printf("iciccc %s\n", global.second->my_map[global.message[1] - 49 + 2]);
        // printf("laaaaa '%c'\n", global.second->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2]);
        if (global.second->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2] != '.') {
            // printf("test1\n");
            // printf("glo %i\n", global.opponent_pid);
            kill(global.opponent_pid, SIGUSR2);
            usleep(4000);
            kill(global.opponent_pid, SIGUSR2);
            global.first->last_shoot = 1;
        } else {
            // printf("test\n");
            // printf("op %d\n", global.opponent_pid);
            kill(global.opponent_pid, SIGUSR2);
            usleep(4000);
            kill(global.opponent_pid, SIGUSR2);
            usleep(4000);
            kill(global.opponent_pid, SIGUSR2);
            global.first->last_shoot = -1;
        }
        // printf("resultaaaat 0 : '%d'\n", global.first->last_shoot);
    } else {
        // printf("opeee %d\n", global.my_pid);
        // printf("turn '%d'\n", global.player_turn);
        // printf("iciccc %s\n", global.first->my_map[global.message[1] - 49 + 2]);
        // printf("laaaaa '%c'\n", global.first->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2]);
        if (global.first->my_map[global.message[1] - 49 + 2][(global.message[0] - 65) * 2 + 2] != '.') {
            kill(global.my_pid, SIGUSR2);
            usleep(4000);
            kill(global.my_pid, SIGUSR2);
            global.second->last_shoot = 1;
        } else {
            kill(global.my_pid, SIGUSR2);
            usleep(4000);
            kill(global.my_pid, SIGUSR2);
            usleep(4000);
            kill(global.my_pid, SIGUSR2);
            global.second->last_shoot = -1;
        }
        // printf("resultaaaat 1 : '%d'\n", global.second->last_shoot);
    }
}
