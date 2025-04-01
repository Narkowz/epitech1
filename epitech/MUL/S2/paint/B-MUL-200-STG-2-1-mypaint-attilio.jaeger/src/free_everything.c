/*
** EPITECH PROJECT, 2024
** free_everything
** File description:
** free_everything
*/

#include "../include/my_paint.h"

void free_everything(global_t *glob)
{
    sfRenderWindow_destroy(glob->window);
    sfRectangleShape_destroy(glob->gui->rect);
    sfTexture_destroy(glob->screen);
    sfSprite_destroy(glob->sheet);
    sfRectangleShape_destroy(glob->gui->brush);
    sfRectangleShape_destroy(glob->gui->eraser);
    sfRectangleShape_destroy(glob->gui->size_up);
    sfRectangleShape_destroy(glob->gui->size_down);
    sfRectangleShape_destroy(glob->menu->filerect);
    sfRectangleShape_destroy(glob->menu->editrect);
    sfRectangleShape_destroy(glob->menu->helprect);
    sfFont_destroy(glob->menu->font);
    sfText_destroy(glob->menu->filetxt);
    sfText_destroy(glob->menu->edittxt);
    sfText_destroy(glob->menu->helptxt);
    free(glob->pixels);
    free(glob->gui);
    free(glob->state);
    free(glob);
}
