/*
** EPITECH PROJECT, 2024
** hover_edit_functions.c
** File description:
** hover_edit_functions
*/

#include "../../../include/my_paint.h"

static void hover_header(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->editrect);

    if (sfFloatRect_contains(&bounds, m.x, m.y) || glob->menu->eisopen) {
        sfRectangleShape_setFillColor(glob->menu->editrect,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->editrect,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->editrect, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->editrect, sfTransparent);
    }
}

static void hover_square(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->square);

    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        sfRectangleShape_setFillColor(glob->menu->square,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->square,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->square, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->square, sfTransparent);
    }
}

static void hover_circle(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->circle);

    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        sfRectangleShape_setFillColor(glob->menu->circle,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->circle,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->circle, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->circle, sfTransparent);
    }
}

void hover_edit(global_t *glob, sfVector2i m)
{
    hover_header(glob, m);
    hover_square(glob, m);
    hover_circle(glob, m);
}
