/*
** EPITECH PROJECT, 2024
** click_help_functions.c
** File description:
** clic_help_functions
*/

#include "../../../include/my_paint.h"

static void coordonates_header(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->editrect);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        if (glob->menu->eisopen) {
            glob->menu->eisopen = sfFalse;
            return;
        }
        glob->menu->eisopen = sfTrue;
        return;
    }
}

static void coordonates_square(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->square);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (glob->menu->eisopen && sfFloatRect_contains(&bounds, m.x, m.y)) {
        glob->state->square = sfTrue;
        glob->state->circle = sfFalse;
        return;
    }
}

static void coordonates_circle(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->circle);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y) && glob->menu->eisopen) {
        glob->state->square = sfFalse;
        glob->state->circle = sfTrue;
        return;
    }
}

void coordonates_edit(global_t *glob)
{
    coordonates_header(glob);
    coordonates_square(glob);
    coordonates_circle(glob);
}
