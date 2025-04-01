/*
** EPITECH PROJECT, 2024
** hover_file_functions.c
** File description:
** hover_file_functions
*/

#include "../../../include/my_paint.h"

void hover_header(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->filerect);

    if (sfFloatRect_contains(&bounds, m.x, m.y) || glob->menu->fisopen) {
        sfRectangleShape_setFillColor(glob->menu->filerect,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->filerect,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->filerect, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->filerect, sfTransparent);
    }
}

static void hover_new(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->new);

    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        sfRectangleShape_setFillColor(glob->menu->new,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->new,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->new, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->new, sfTransparent);
    }
}

static void hover_open(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->open);

    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        sfRectangleShape_setFillColor(glob->menu->open,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->open,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->open, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->open, sfTransparent);
    }
}

static void hover_save(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->save);

    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        sfRectangleShape_setFillColor(glob->menu->save,
            (sfColor) {160, 160, 160, 255});
        sfRectangleShape_setOutlineColor(glob->menu->save,
            (sfColor) {128, 128, 128, 255});
    } else {
        sfRectangleShape_setFillColor(glob->menu->save, sfTransparent);
        sfRectangleShape_setOutlineColor(glob->menu->save, sfTransparent);
    }
}

void hover_file(global_t *glob, sfVector2i m)
{
    hover_header(glob, m);
    hover_new(glob, m);
    hover_save(glob, m);
    hover_open(glob, m);
}
