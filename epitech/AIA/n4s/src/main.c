/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** main
*/

#include "../include/need4stek.h"

int main(void)
{
    size_t size = 0;
    all_t all;

    all.lap = 0;
    all.buf = NULL;
    all.coo_lidar = NULL;
    write(1, "START_SIMULATION\n", 17);
    getline(&all.buf, &size, stdin);
    write_ev(&all, size, "CAR_FORWARD:0.5\n");
    handling_turn(size, &all);
    write(1, "STOP_SIMULATION\n", 16);
    getline(&all.buf, &size, stdin);
    free(all.buf);
    for (int i = 0; all.coo_lidar[i] != NULL; i++)
        free(all.coo_lidar[i]);
    free(all.coo_lidar);
    return 0;
}
