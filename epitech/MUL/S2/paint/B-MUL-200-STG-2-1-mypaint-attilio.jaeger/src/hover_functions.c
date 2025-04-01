/*
** EPITECH PROJECT, 2024
** hover_functions.c
** File description:
** hover_functions
*/

#include "../include/my_paint.h"

static void hover_brush(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->gui->brush);

    if (sfFloatRect_contains(&bounds, m.x, m.y))
        sfRectangleShape_setOutlineColor(glob->gui->brush, sfBlack);
    else
        sfRectangleShape_setOutlineColor(glob->gui->brush, sfTransparent);
}

static void hover_eraser(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->gui->eraser);

    if (sfFloatRect_contains(&bounds, m.x, m.y))
        sfRectangleShape_setOutlineColor(glob->gui->eraser, sfBlack);
    else
        sfRectangleShape_setOutlineColor(glob->gui->eraser, sfTransparent);
}

static void hover_sizeup(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->gui->size_up);

    if (sfFloatRect_contains(&bounds, m.x, m.y))
        sfRectangleShape_setOutlineColor(glob->gui->size_up, sfBlack);
    else
        sfRectangleShape_setOutlineColor(glob->gui->size_up, sfTransparent);
}

static void hover_sizedown(global_t *glob, sfVector2i m)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->gui->size_down);

    if (sfFloatRect_contains(&bounds, m.x, m.y))
        sfRectangleShape_setOutlineColor(glob->gui->size_down, sfBlack);
    else
        sfRectangleShape_setOutlineColor(glob->gui->size_down, sfTransparent);
}

void hover_function(global_t *glob)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(glob->window);

    hover_brush(glob, m);
    hover_eraser(glob, m);
    hover_sizeup(glob, m);
    hover_sizedown(glob, m);
    hover_file(glob, m);
    hover_edit(glob, m);
    hover_help(glob, m);
}
