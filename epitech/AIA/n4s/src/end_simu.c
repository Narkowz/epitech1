/*
** EPITECH PROJECT, 2024
** N4S
** File description:
** end_simu.c
*/

#include "../include/need4stek.h"

void end_simu(all_t *all, size_t size)
{
    write(1, "STOP_SIMULATION\n", 16);
    getline(&all->buf, &size, stdin);
    exit(0);
}
