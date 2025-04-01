/*
** EPITECH PROJECT, 2024
** draw_everything.c
** File description:
** draw_everything
*/

#include "../include/my_paint.h"

static void set_size_responsive(global_t *glob, sfVector2u size)
{
    sfRectangleShape_setPosition(glob->gui->brush, (sfVector2f)
        {size.x * 1 / 3, 75});
}

static void draw_buttons(global_t *glob)
{
    sfRenderWindow_drawRectangleShape(glob->window, glob->gui->rect, 0);
    sfRenderWindow_drawRectangleShape(glob->window, glob->gui->brush, 0);
    sfRenderWindow_drawRectangleShape(glob->window, glob->gui->eraser, 0);
    sfRenderWindow_drawRectangleShape(glob->window, glob->gui->size_up, 0);
    sfRenderWindow_drawRectangleShape(glob->window, glob->gui->size_down, 0);
    sfRenderWindow_drawSprite(glob->window, glob->gui->sbrush, NULL);
    sfRenderWindow_drawSprite(glob->window, glob->gui->seraser, NULL);
    sfRenderWindow_drawSprite(glob->window, glob->gui->sdown, NULL);
    sfRenderWindow_drawSprite(glob->window, glob->gui->sup, NULL);
    if (glob->gui->isabout) {
        sfRenderWindow_drawRectangleShape(glob->window, glob->gui->aboutrect,
            0);
        sfRenderWindow_drawText(glob->window, glob->gui->about, 0);
    }
}

static void draw_menu_bar(global_t *glob)
{
    sfRenderWindow_drawRectangleShape(glob->window, glob->menu->filerect, 0);
    if (glob->menu->fisopen) {
        sfRenderWindow_drawRectangleShape(glob->window, glob->menu->save, 0);
        sfRenderWindow_drawText(glob->window, glob->menu->savetxt, 0);
        sfRenderWindow_drawRectangleShape(glob->window, glob->menu->new, 0);
        sfRenderWindow_drawText(glob->window, glob->menu->newtxt, 0);
        sfRenderWindow_drawRectangleShape(glob->window, glob->menu->open, 0);
        sfRenderWindow_drawText(glob->window, glob->menu->opentxt, 0);
    }
    if (glob->aled->isaled) {
        sfRenderWindow_drawText(glob->window, glob->aled->brush, 0);
        sfRenderWindow_drawText(glob->window, glob->aled->up, 0);
        sfRenderWindow_drawText(glob->window, glob->aled->down, 0);
        sfRenderWindow_drawText(glob->window, glob->aled->eraser, 0);
        sfRenderWindow_drawText(glob->window, glob->aled->edit, 0);
        sfRenderWindow_drawText(glob->window, glob->aled->shape, 0);
    }
    sfRenderWindow_drawRectangleShape(glob->window, glob->menu->editrect, 0);
    sfRenderWindow_drawRectangleShape(glob->window, glob->menu->helprect, 0);
    sfRenderWindow_drawText(glob->window, glob->menu->filetxt, 0);
}

void draw_dependancies(global_t *glob)
{
    if (glob->menu->hisopen) {
        sfRenderWindow_drawRectangleShape(glob->window, glob->menu->about, 0);
        sfRenderWindow_drawText(glob->window, glob->menu->abouttxt, 0);
        sfRenderWindow_drawRectangleShape(glob->window, glob->menu->aled, 0);
        sfRenderWindow_drawText(glob->window, glob->menu->aledtxt, 0);
    }
    if (glob->menu->eisopen) {
        sfRenderWindow_drawRectangleShape(glob->window, glob->menu->square, 0);
        sfRenderWindow_drawText(glob->window, glob->menu->squaretxt, 0);
        sfRenderWindow_drawRectangleShape(glob->window, glob->menu->circle, 0);
        sfRenderWindow_drawText(glob->window, glob->menu->circletxt, 0);
    }
    if (glob->gui->openisopen) {
        sfRenderWindow_drawRectangleShape(glob->window, glob->gui->openrect,
        0);
        sfRenderWindow_drawRectangleShape(glob->window, glob->gui->clip, 0);
        sfRenderWindow_drawText(glob->window, glob->gui->open, 0);
    }
    sfRenderWindow_drawText(glob->window, glob->menu->edittxt, 0);
    sfRenderWindow_drawText(glob->window, glob->menu->helptxt, 0);
}

void draw_everything(global_t *glob)
{
    sfVector2u size = sfRenderWindow_getSize(glob->window);

    set_size_responsive(glob, size);
    sfRenderWindow_drawSprite(glob->window, glob->sheet, NULL);
    draw_buttons(glob);
    draw_menu_bar(glob);
    draw_dependancies(glob);
}
