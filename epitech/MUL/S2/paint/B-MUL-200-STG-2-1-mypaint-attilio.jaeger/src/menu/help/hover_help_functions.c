/*
** EPITECH PROJECT, 2024
** hover_help_functions.c
** File description:
** hover_help_functions
*/

#include "../../../include/my_paint.h"

static void hover_header(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->helprect);

    if (sfFloatRect_contains(&bounds, m.x, m.y) || glob->menu->hisopen) {
        sfRectangleShape_setFillColor(glob->menu->helprect,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->helprect,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->helprect, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->helprect, sfTransparent);
    }
}

static void hover_about(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->about);

    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        sfRectangleShape_setFillColor(glob->menu->about,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->about,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->about, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->about, sfTransparent);
    }
}

static void hover_aled(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->aled);

    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        sfRectangleShape_setFillColor(glob->menu->aled,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->aled,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->aled, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->aled, sfTransparent);
    }
}

void hover_help(global_t *glob, sfVector2i m)
{
    hover_header(glob, m);
    hover_about(glob, m);
    hover_aled(glob, m);
}
