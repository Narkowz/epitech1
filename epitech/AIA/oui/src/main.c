/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** main
*/

#include "../include/need4stek.h"

int main(void)
{
    char *buf = NULL;
    size_t size = 0;
    char **coo_lidar = NULL;

    write(1, "START_SIMULATION\n", 17);
    getline(&buf, &size, stdin);
    sleep(1);
    write(1, "CAR_FORWARD:0.5\n", 16);
    getline(&buf, &size, stdin);
    sleep(1);
    handling_turn(buf, size, coo_lidar);
    write(1, "STOP_SIMULATION\n", 16);
    getline(&buf, &size, stdin);
    return 0;
}
