/*
** EPITECH PROJECT, 2023
** free_list.c
** File description:
** free_list
*/

#include "include/my_radar.h"

void free_plane(plane_t *plane)
{
    plane_t *temp = plane;

    while (plane != NULL) {
        temp = plane;
        plane = plane->next;
        sfTexture_destroy(temp->plane);
        sfSprite_destroy(temp->plane_sprite);
        free(temp);
    }
    free(plane);
}

void free_tower(radar_t *radar)
{
    radar_t *temp = radar;

    while (radar != NULL) {
        temp = radar;
        radar = radar->next;
        sfTexture_destroy(temp->tower);
        sfSprite_destroy(temp->tower_sprite);
        free(temp);
    }
    free(radar);
}

void free_list(window_t *window, radar_t *radar, plane_t *plane)
{
    free_plane(plane);
    free_tower(radar);
    sfClock_destroy(window->clock);
    sfClock_destroy(window->timer);
    free(window);
}
