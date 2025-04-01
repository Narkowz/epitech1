/*
** EPITECH PROJECT, 2024
** click_help_functions.c
** File description:
** click_help_functions
*/

#include "../../../include/my_paint.h"


static void coordonates_header(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->helprect);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        if (glob->menu->hisopen) {
            glob->menu->hisopen = sfFalse;
            return;
        }
        glob->menu->hisopen = sfTrue;
        return;
    }
}

static void coordonates_about(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->about);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y) && glob->menu->hisopen) {
        glob->gui->isabout = sfTrue;
        return;
    }
}

static void coordonates_aled(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->aled);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y) && glob->menu->hisopen) {
        if (glob->aled->isaled) {
            glob->aled->isaled = sfFalse;
            return;
        }
        glob->aled->isaled = sfTrue;
        return;
    }
}

void coordonates_help(global_t *glob)
{
    coordonates_header(glob);
    coordonates_about(glob);
    coordonates_aled(glob);
}
