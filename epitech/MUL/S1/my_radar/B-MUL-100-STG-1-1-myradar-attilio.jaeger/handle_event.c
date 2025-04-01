/*
** EPITECH PROJECT, 2023
** handle_event.c
** File description:
** handle_event
*/

#include "include/my_radar.h"

void hitboxes(window_t *window)
{
    static float time = 0;
    static float ntime = 0;

    window->time = sfClock_getElapsedTime(window->clock);
    time = sfTime_asSeconds(window->time);
    if (window->disp_hitbox == 0 && (time - ntime) > 0.05)
        window->disp_hitbox = 1;
    else if (window->disp_hitbox == 1 && (time - ntime) > 0.05)
        window->disp_hitbox = 0;
    window->time = sfClock_getElapsedTime(window->clock);
    ntime = sfTime_asSeconds(window->time);
}

void disp_sprite(window_t *window)
{
    static float time1 = 0;
    static float ntime1 = 0;

    window->time = sfClock_getElapsedTime(window->clock);
    time1 = sfTime_asSeconds(window->time);
    if (window->disp_sprite == 0 && (time1 - ntime1) > 0.05)
        window->disp_sprite = 1;
    else if (window->disp_sprite == 1 && (time1 - ntime1) > 0.05)
        window->disp_sprite = 0;
    window->time = sfClock_getElapsedTime(window->clock);
    ntime1 = sfTime_asSeconds(window->time);
}

void handle_event(window_t *window, radar_t *radar, plane_t *plane)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyL) && window->game_running == 0)
            hitboxes(window);
        if (sfKeyboard_isKeyPressed(sfKeyS) && window->game_running == 0)
            disp_sprite(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
            window->game_running == -1) {
            window->game_running = 0;
            window->timer = sfClock_create();
        }
    }
}
