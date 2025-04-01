/*
** EPITECH PROJECT, 2024
** display_list.c
** File description:
** display_list
*/

#include "include/my_radar.h"

void draw_function(window_t *window, plane_t *temp_p)
{
    if (temp_p->reached != 1 && temp_p->collide != 1 &&
        get_time(window) >= temp_p->delay) {
        if (window->disp_sprite == 1)
            sfRenderWindow_drawSprite(window->window, temp_p->plane_sprite, 0);
        if (window->disp_hitbox == 1)
            sfRenderWindow_drawRectangleShape(window->window,
                temp_p->hitbox, 0);
    }
}

void my_show_list(radar_t *radar, plane_t *plane, window_t *window)
{
    radar_t *temp = radar;
    plane_t *temp_p = plane;

    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, window->back_sprite, 0);
    while (temp != NULL) {
        sfRenderWindow_drawSprite(window->window, temp->tower_sprite, 0);
        sfRenderWindow_drawCircleShape(window->window, temp->circle, 0);
        temp = temp->next;
    }
    while (temp_p != NULL) {
        draw_function(window, temp_p);
        temp_p = temp_p->next;
    }
}
