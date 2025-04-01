/*
** EPITECH PROJECT, 2024
** menu.c
** File description:
** menu
*/

#include "include/my_radar.h"

void menu(window_t *window, radar_t *radar, plane_t *plane)
{
    handle_event(window, radar, plane);
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, window->back_sprite, 0);
    sfText_setOrigin(window->menu, (sfVector2f){290, 100});
    sfText_setOrigin(window->space, (sfVector2f){300, 0});
    sfText_setString(window->menu, "MY RADAR");
    sfText_setString(window->space, "Press SPACE to start simulation");
    sfText_setCharacterSize(window->menu, 100);
    sfText_setCharacterSize(window->space, 30);
    sfText_setFont(window->menu, window->font);
    sfText_setFont(window->space, window->font);
    sfText_setPosition(window->menu, window->pos_screen);
    sfText_setPosition(window->space, (sfVector2f){window->pos_screen.x,
        window->pos_screen.y + 100});
    sfText_setFillColor(window->menu, sfWhite);
    sfText_setFillColor(window->space, sfWhite);
    sfRenderWindow_drawText(window->window, window->menu, 0);
    sfRenderWindow_drawText(window->window, window->space, 0);
    sfRenderWindow_display(window->window);
}
