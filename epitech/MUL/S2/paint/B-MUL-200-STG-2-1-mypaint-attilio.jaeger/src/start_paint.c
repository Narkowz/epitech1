/*
** EPITECH PROJECT, 2024
** start_paint.c
** File description:
** start_paint
*/

#include "../include/my_paint.h"

void prepare_sheet(global_t *glob)
{
    for (int i = 0; i < 1920 * 1080 * 4; i++)
        glob->pixels[i] = 255;
}

static global_t *init_window(global_t *glob)
{
    sfVideoMode mode = {1920, 1080, 64};

    glob->gui = malloc(sizeof(gui_t));
    glob->state = malloc(sizeof(state_t));
    glob->pixels = malloc(1920 * 1080 * 4);
    glob->menu = malloc(sizeof(menu_t));
    glob->aled = malloc(sizeof(aled_t));
    glob->pixel_size = 10;
    glob->is_drawing = sfFalse;
    glob->gui->eraser = sfFalse;
    glob->menu->font = sfFont_createFromFile("assets/Roboto-Medium.ttf");
    glob->state->brush = sfFalse;
    glob->state->eraser = sfFalse;
    glob->sheet = sfSprite_create();
    glob->window = sfRenderWindow_create(mode,
        "Paint", sfClose | sfResize, NULL);
    glob->screen = sfTexture_create(1920, 1080);
    sfRenderWindow_setPosition(glob->window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(glob->window, 60);
    return glob;
}

void start_paint(global_t *glob)
{
    glob = init_window(glob);
    sfSprite_setTexture(glob->sheet, glob->screen, sfTrue);
    sfRenderWindow_clear(glob->window, sfWhite);
    prepare_sheet(glob);
    sfTexture_updateFromPixels(glob->screen, glob->pixels, 1920, 1080, 0, 0);
    init_gui(glob);
    while (sfRenderWindow_isOpen(glob->window)) {
        draw_everything(glob);
        sfRenderWindow_display(glob->window);
        handle_event(glob);
    }
    free_everything(glob);
    return;
}
