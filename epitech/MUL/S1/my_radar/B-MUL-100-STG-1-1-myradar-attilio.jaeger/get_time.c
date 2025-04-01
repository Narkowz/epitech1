/*
** EPITECH PROJECT, 2024
** get_time.c
** File description:
** get_time
*/

#include "include/my_radar.h"

int get_time(window_t *window)
{
    int seconds = 0;

    window->time = sfClock_getElapsedTime(window->clock);
    seconds = (int)sfTime_asSeconds(window->time);
    return seconds;
}
