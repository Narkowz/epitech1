/*
** EPITECH PROJECT, 2024
** draw_file_menu.c
** File description:
** draw_file_menu
*/

#include "../../../include/my_paint.h"

static void init_header(global_t *glob)
{
    glob->menu->filetxt = sfText_create();
    glob->menu->filerect = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->filerect, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->filerect, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->filerect,
        (sfVector2f) {32, 12});
    sfRectangleShape_setFillColor(glob->menu->filerect, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->filerect, 1.0f);
    sfText_setFont(glob->menu->filetxt, glob->menu->font);
    sfText_setString(glob->menu->filetxt, "File");
    sfText_setCharacterSize(glob->menu->filetxt, 20);
    sfText_setPosition(glob->menu->filetxt, (sfVector2f) {15, 0});
    sfText_setFillColor(glob->menu->filetxt, sfBlack);
}

static void init_new_file(global_t *glob)
{
    glob->menu->newtxt = sfText_create();
    glob->menu->new = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->new, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->new, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->new,
        (sfVector2f) {32, 35});
    sfRectangleShape_setFillColor(glob->menu->new, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->new, 1.0f);
    sfText_setFont(glob->menu->newtxt, glob->menu->font);
    sfText_setString(glob->menu->newtxt, "New");
    sfText_setCharacterSize(glob->menu->newtxt, 20);
    sfText_setPosition(glob->menu->newtxt, (sfVector2f) {11, 22});
    sfText_setFillColor(glob->menu->newtxt, sfBlack);
}

static void init_open_file(global_t *glob)
{
    glob->menu->opentxt = sfText_create();
    glob->menu->open = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->open, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->open, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->open,
        (sfVector2f) {32, 58});
    sfRectangleShape_setFillColor(glob->menu->open, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->open, 1.0f);
    sfText_setFont(glob->menu->opentxt, glob->menu->font);
    sfText_setString(glob->menu->opentxt, "Open");
    sfText_setCharacterSize(glob->menu->opentxt, 20);
    sfText_setPosition(glob->menu->opentxt, (sfVector2f) {11, 44});
    sfText_setFillColor(glob->menu->opentxt, sfBlack);
}

static void init_save_file(global_t *glob)
{
    glob->menu->savetxt = sfText_create();
    glob->menu->save = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->save, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->save, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->save,
        (sfVector2f) {32, 81});
    sfRectangleShape_setFillColor(glob->menu->save, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->save, 1.0f);
    sfText_setFont(glob->menu->savetxt, glob->menu->font);
    sfText_setString(glob->menu->savetxt, "Save");
    sfText_setCharacterSize(glob->menu->savetxt, 20);
    sfText_setPosition(glob->menu->savetxt, (sfVector2f) {11, 66});
    sfText_setFillColor(glob->menu->savetxt, sfBlack);
}

void init_open_me(global_t *glob)
{
    sfVector2u s = sfRenderWindow_getSize(glob->window);

    glob->gui->openrect = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->openrect, (sfVector2f) {250, 100});
    sfRectangleShape_setOrigin(glob->gui->openrect, (sfVector2f) {125, 50});
    sfRectangleShape_setPosition(glob->gui->openrect,
        (sfVector2f) {s.x / 2, s.y / 2});
    sfRectangleShape_setFillColor(glob->gui->openrect, (sfColor)
        {255, 204, 255, 255});
    sfRectangleShape_setOutlineColor(glob->gui->openrect, sfBlack);
    sfRectangleShape_setOutlineThickness(glob->gui->openrect, 1.0f);
}

void init_clipboard(global_t *glob)
{
    sfVector2u s = sfRenderWindow_getSize(glob->window);

    glob->gui->open = sfText_create();
    glob->gui->clip = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->clip, (sfVector2f) {150, 50});
    sfRectangleShape_setOrigin(glob->gui->clip, (sfVector2f) {75, 25});
    sfRectangleShape_setPosition(glob->gui->clip,
        (sfVector2f) {s.x / 2, s.y / 2});
    sfRectangleShape_setFillColor(glob->gui->clip, (sfColor)
        {255, 255, 255, 100});
    sfRectangleShape_setOutlineColor(glob->gui->clip, sfBlack);
    sfRectangleShape_setOutlineThickness(glob->gui->clip, 1.0f);
    sfText_setFont(glob->gui->open, glob->menu->font);
    sfText_setCharacterSize(glob->gui->open, 20);
    sfText_setString(glob->gui->open, "Paste clipboard");
    sfText_setPosition(glob->gui->open, (sfVector2f) {(s.x / 2) - 70,
        (s.y / 2) - 12});
    sfText_setFillColor(glob->gui->open, sfBlack);
}

void init_file(global_t *glob)
{
    glob->menu->fisopen = sfFalse;
    glob->gui->openisopen = sfFalse;
    init_header(glob);
    init_new_file(glob);
    init_open_file(glob);
    init_save_file(glob);
    init_open_me(glob);
    init_clipboard(glob);
}
