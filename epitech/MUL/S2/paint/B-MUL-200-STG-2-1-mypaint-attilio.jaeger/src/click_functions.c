/*
** EPITECH PROJECT, 2024
** click_functions.c
** File description:
** click_functions
*/

#include "../include/my_paint.h"

static void coordonates_size(global_t *glob)
{
    sfVector2i m;
    sfFloatRect boundsUp;
    sfFloatRect boundsDown;

    m = sfMouse_getPositionRenderWindow(glob->window);
    boundsUp = sfRectangleShape_getGlobalBounds(glob->gui->size_up);
    if (sfFloatRect_contains(&boundsUp, m.x, m.y)) {
        glob->pixel_size += 1;
        return;
    }
    boundsDown = sfRectangleShape_getGlobalBounds(glob->gui->size_down);
    if (sfFloatRect_contains(&boundsDown, m.x, m.y)) {
        glob->pixel_size -= 1;
        if (glob->pixel_size < 1)
            glob->pixel_size = 1;
        return;
    }
}

static void coordonates_tools(global_t *glob)
{
    sfVector2i m;
    sfFloatRect boundsBrush;
    sfFloatRect boundsEraser;

    m = sfMouse_getPositionRenderWindow(glob->window);
    boundsBrush = sfRectangleShape_getGlobalBounds(glob->gui->brush);
    if (sfFloatRect_contains(&boundsBrush, m.x, m.y)) {
        if (glob->state->eraser)
            glob->state->eraser = sfFalse;
        glob->state->brush = sfTrue;
        return;
    }
    boundsEraser = sfRectangleShape_getGlobalBounds(glob->gui->eraser);
    if (sfFloatRect_contains(&boundsEraser, m.x, m.y)) {
        if (glob->state->brush)
            glob->state->brush = sfFalse;
        glob->state->eraser = sfTrue;
        return;
    }
}

static void click_nothing(global_t *glob)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(glob->window);
    sfFloatRect boundsrect = sfRectangleShape_getGlobalBounds(glob->gui->rect);
    sfFloatRect boundsheet = sfSprite_getGlobalBounds(glob->sheet);

    if ((glob->menu->fisopen || glob->menu->hisopen || glob->gui->isabout ||
        glob->menu->eisopen) && (!sfFloatRect_contains(&boundsrect, m.x, m.y)
        || !sfFloatRect_contains(&boundsheet, m.x, m.y))) {
        glob->menu->fisopen = sfFalse;
        glob->menu->hisopen = sfFalse;
        glob->menu->eisopen = sfFalse;
        glob->gui->isabout = sfFalse;
        return;
    }
}

static void get_coordonates(global_t *glob)
{
    click_nothing(glob);
    coordonates_tools(glob);
    coordonates_size(glob);
    coordonates_file(glob);
    coordonates_help(glob);
    coordonates_edit(glob);
}

void event_click(global_t *glob)
{
    if (glob->event.type == sfEvtMouseButtonPressed &&
        (glob->state->brush || glob->state->eraser))
        glob->is_drawing = sfTrue;
    if (glob->event.type == sfEvtMouseButtonReleased)
        glob->is_drawing = sfFalse;
    if (glob->is_drawing && glob->event.type == sfEvtMouseMoved &&
        glob->state->brush)
        init_function(glob);
    if (glob->is_drawing && glob->event.type == sfEvtMouseMoved &&
        glob->state->eraser)
        eraser_function(glob);
    if (glob->event.type == sfEvtMouseButtonPressed &&
        glob->event.mouseButton.button == sfMouseLeft)
        get_coordonates(glob);
    if (glob->event.type == sfEvtMouseButtonReleased &&
        glob->event.mouseButton.button == sfMouseRight) {
        glob->state->brush = sfFalse;
        glob->state->eraser = sfFalse;
    }
}
