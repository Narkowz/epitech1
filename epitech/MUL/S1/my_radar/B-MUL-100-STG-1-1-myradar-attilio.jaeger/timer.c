/*
** EPITECH PROJECT, 2024
** timer.c
** File description:
** timer
*/

#include "include/my_radar.h"

sfText *timer_init(window_t *window)
{
    sfText *timerText = sfText_create();

    sfText_setFont(timerText, window->font);
    sfText_setCharacterSize(timerText, 24);
    sfText_setPosition(timerText, (sfVector2f){1820.f, 10.f});
    sfText_setFillColor(timerText, sfWhite);
    return timerText;
}

void draw_timer_update(sfText *text, int currentTime)
{
    int minutes = currentTime / 60;
    int seconds = currentTime % 60;
    char timerString[10];

    timerString[0] = '0' + (minutes / 10);
    timerString[1] = '0' + (minutes % 10);
    timerString[2] = ':';
    timerString[3] = '0' + (seconds / 10);
    timerString[4] = '0' + (seconds % 10);
    timerString[5] = '\0';
    sfText_setString(text, timerString);
}

void draw_timer(window_t *window)
{
    sfText *text = timer_init(window);
    sfTime elapsed = sfClock_getElapsedTime(window->timer);
    sfTime time = sfMilliseconds(1000);
    static int currentTime = 0;
    int minutes;
    int seconds;
    char timerString[10];

    if (sfTime_asMilliseconds(elapsed) >= sfTime_asMilliseconds(time)) {
        sfClock_restart(window->timer);
        currentTime += 1;
    }
    draw_timer_update(text, currentTime);
    sfRenderWindow_drawText(window->window, text, NULL);
}
