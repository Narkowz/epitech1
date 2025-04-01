/*
** EPITECH PROJECT, 2024
** init_aled_text.c
** File description:
** init_aled_text
*/

#include "../../../include/my_paint.h"

void init_aled_brush(global_t *glob)
{
    sfVector2f p = sfRectangleShape_getPosition(glob->gui->brush);

    glob->aled->brush = sfText_create();
    sfText_setFont(glob->aled->brush, glob->menu->font);
    sfText_setString(glob->aled->brush, "Brush");
    sfText_setCharacterSize(glob->aled->brush, 20);
    sfText_setPosition(glob->aled->brush, (sfVector2f) {p.x - 25, p.y + 20});
    sfText_setFillColor(glob->aled->brush, sfBlack);
}

void init_aled_up(global_t *glob)
{
    sfVector2f p = sfRectangleShape_getPosition(glob->gui->size_up);

    glob->aled->up = sfText_create();
    sfText_setFont(glob->aled->up, glob->menu->font);
    sfText_setString(glob->aled->up, "Size up");
    sfText_setCharacterSize(glob->aled->up, 20);
    sfText_setPosition(glob->aled->up, (sfVector2f) {p.x - 30, p.y - 45});
    sfText_setFillColor(glob->aled->up, sfBlack);
}

void init_aled_down(global_t *glob)
{
    sfVector2f p = sfRectangleShape_getPosition(glob->gui->size_down);

    glob->aled->down = sfText_create();
    sfText_setFont(glob->aled->down, glob->menu->font);
    sfText_setString(glob->aled->down, "Size down");
    sfText_setCharacterSize(glob->aled->down, 20);
    sfText_setPosition(glob->aled->down, (sfVector2f) {p.x - 45, p.y + 20});
    sfText_setFillColor(glob->aled->down, sfBlack);
}

void init_aled_eraser(global_t *glob)
{
    sfVector2f p = sfRectangleShape_getPosition(glob->gui->eraser);

    glob->aled->eraser = sfText_create();
    sfText_setFont(glob->aled->eraser, glob->menu->font);
    sfText_setString(glob->aled->eraser, "Eraser");
    sfText_setCharacterSize(glob->aled->eraser, 20);
    sfText_setPosition(glob->aled->eraser, (sfVector2f) {p.x - 30, p.y + 20});
    sfText_setFillColor(glob->aled->eraser, sfBlack);
}

static void init_aled_edit(global_t *glob)
{
    sfVector2f p = sfRectangleShape_getPosition(glob->menu->editrect);

    glob->aled->edit = sfText_create();
    sfText_setFont(glob->aled->edit, glob->menu->font);
    sfText_setString(glob->aled->edit, "Edit->square or circle");
    sfText_setCharacterSize(glob->aled->edit, 20);
    sfText_setPosition(glob->aled->edit, (sfVector2f) {p.x + 100, p.y + 25});
    sfText_setFillColor(glob->aled->edit, sfBlack);
}

static void init_aled_shape(global_t *glob)
{
    sfVector2f p = sfRectangleShape_getPosition(glob->menu->editrect);

    glob->aled->shape = sfText_create();
    sfText_setFont(glob->aled->shape, glob->menu->font);
    sfText_setString(glob->aled->shape, "Change brush and eraser shape");
    sfText_setCharacterSize(glob->aled->shape, 20);
    sfText_setPosition(glob->aled->shape, (sfVector2f) {p.x + 100, p.y + 7});
    sfText_setFillColor(glob->aled->shape, sfBlack);
}

void init_aled_wind(global_t *glob)
{
    glob->aled->isaled = sfFalse;
    init_aled_brush(glob);
    init_aled_up(glob);
    init_aled_down(glob);
    init_aled_eraser(glob);
    init_aled_edit(glob);
    init_aled_shape(glob);
}
