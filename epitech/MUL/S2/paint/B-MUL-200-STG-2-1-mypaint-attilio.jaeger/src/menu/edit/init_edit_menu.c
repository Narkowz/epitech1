/*
** EPITECH PROJECT, 2024
** draw_edit_menu.c
** File description:
** draw_edit_menu
*/

#include "../../../include/my_paint.h"

static void init_header(global_t *glob)
{
    glob->menu->edittxt = sfText_create();
    glob->menu->editrect = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->editrect, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->editrect, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->editrect,
        (sfVector2f) {94, 12});
    sfRectangleShape_setFillColor(glob->menu->editrect, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->editrect, 1.0f);
    sfText_setFont(glob->menu->edittxt, glob->menu->font);
    sfText_setString(glob->menu->edittxt, "Edit");
    sfText_setCharacterSize(glob->menu->edittxt, 20);
    sfText_setPosition(glob->menu->edittxt, (sfVector2f) {75, 0});
    sfText_setFillColor(glob->menu->edittxt, sfBlack);
}

static void init_square(global_t *glob)
{
    glob->menu->squaretxt = sfText_create();
    glob->menu->square = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->square, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->square, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->square,
        (sfVector2f) {94, 35});
    sfRectangleShape_setFillColor(glob->menu->square, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->square, 1.0f);
    sfText_setFont(glob->menu->squaretxt, glob->menu->font);
    sfText_setString(glob->menu->squaretxt, "Square");
    sfText_setCharacterSize(glob->menu->squaretxt, 20);
    sfText_setPosition(glob->menu->squaretxt, (sfVector2f) {65, 22});
    sfText_setFillColor(glob->menu->squaretxt, sfBlack);
}

static void init_circle(global_t *glob)
{
    glob->menu->circletxt = sfText_create();
    glob->menu->circle = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->circle, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->circle, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->circle,
        (sfVector2f) {94, 58});
    sfRectangleShape_setFillColor(glob->menu->circle, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->circle, 1.0f);
    sfText_setFont(glob->menu->circletxt, glob->menu->font);
    sfText_setString(glob->menu->circletxt, "Circle");
    sfText_setCharacterSize(glob->menu->circletxt, 20);
    sfText_setPosition(glob->menu->circletxt, (sfVector2f) {65, 44});
    sfText_setFillColor(glob->menu->circletxt, sfBlack);
}

void init_edit(global_t *glob)
{
    glob->menu->eisopen = sfFalse;
    glob->state->square = sfTrue;
    glob->state->circle = sfFalse;
    init_header(glob);
    init_square(glob);
    init_circle(glob);
}
