/*
** EPITECH PROJECT, 2024
** click_file_functions.c
** File description:
** click_file_functions
*/

#include "../../../include/my_paint.h"

static void coordonates_header(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->filerect);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y)) {
        if (glob->menu->fisopen) {
            glob->menu->fisopen = sfFalse;
            return;
        }
        glob->menu->fisopen = sfTrue;
        return;
    }
    bounds = sfRectangleShape_getGlobalBounds(glob->menu->save);
    if (glob->menu->fisopen && sfFloatRect_contains(&bounds, m.x, m.y)) {
        glob->menu->fisopen = sfFalse;
        create_screenshot(glob);
        return;
    }
}

static void coordonates_new_file(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->new);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y) && glob->menu->fisopen) {
        prepare_sheet(glob);
        sfTexture_updateFromPixels(glob->screen, glob->pixels,
            1920, 1080, 0, 0);
        glob->menu->fisopen = sfFalse;
        return;
    }
}

static void coordonates_open_file(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->menu->open);

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y) && glob->menu->fisopen) {
        glob->gui->openisopen = sfTrue;
        return;
    }
}

void coordonates_clipboard(global_t *glob)
{
    sfVector2i m;
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(glob->gui->clip);
    sfTexture *texture;

    m = sfMouse_getPositionRenderWindow(glob->window);
    if (sfFloatRect_contains(&bounds, m.x, m.y) && glob->gui->openisopen) {
        glob->filepath = sfClipboard_getString();
        texture = sfTexture_createFromFile(glob->filepath, NULL);
        if (texture == NULL) {
            glob->gui->openisopen = sfTrue;
            return;
        }
        sfTexture_updateFromTexture(glob->screen, texture, 0, 0);
        glob->screen = texture;
        sfSprite_setTexture(glob->sheet, glob->screen, sfFalse);
        glob->gui->openisopen = sfFalse;
        return;
    }
}

void coordonates_file(global_t *glob)
{
    coordonates_header(glob);
    coordonates_open_file(glob);
    coordonates_new_file(glob);
    coordonates_clipboard(glob);
}
