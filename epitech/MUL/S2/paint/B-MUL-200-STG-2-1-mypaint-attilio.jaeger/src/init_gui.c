/*
** EPITECH PROJECT, 2024
** draw_gui.c
** File description:
** draw_gui
*/

#include "../include/my_paint.h"

static void init_line(global_t *glob)
{
    sfColor grayColor = {192, 192, 192, 255};

    glob->gui->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->rect, (sfVector2f) {1920, 150});
    sfRectangleShape_setPosition(glob->gui->rect, (sfVector2f) {0, 0});
    sfRectangleShape_setFillColor(glob->gui->rect, grayColor);
    sfRectangleShape_setOutlineColor(glob->gui->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(glob->gui->rect, 1.0f);
}

static void init_brush(global_t *glob)
{
    glob->gui->brush = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->brush, (sfVector2f) {30, 30});
    sfRectangleShape_setOrigin(glob->gui->brush, (sfVector2f) {15, 15});
    sfRectangleShape_setPosition(glob->gui->brush,
        (sfVector2f) {1920 * 1 / 3, 75});
    sfRectangleShape_setFillColor(glob->gui->brush, sfTransparent);
    sfRectangleShape_setOutlineColor(glob->gui->brush, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->gui->brush, 2.0f);
    glob->gui->tbrush = sfTexture_createFromFile("assets/Brush.png", NULL);
    glob->gui->sbrush = sfSprite_create();
    sfSprite_setTexture(glob->gui->sbrush, glob->gui->tbrush, sfFalse);
    sfSprite_setPosition(glob->gui->sbrush, (sfVector2f) {627, 63});
    sfSprite_setScale(glob->gui->sbrush, (sfVector2f) {0.05, 0.05});
}

static void init_eraser(global_t *glob)
{
    glob->gui->eraser = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->eraser, (sfVector2f) {30, 30});
    sfRectangleShape_setOrigin(glob->gui->eraser, (sfVector2f) {15, 15});
    sfRectangleShape_setPosition(glob->gui->eraser,
        (sfVector2f) {1920 * 2 / 3, 75});
    sfRectangleShape_setFillColor(glob->gui->eraser, sfTransparent);
    sfRectangleShape_setOutlineColor(glob->gui->eraser, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->gui->eraser, 2.0f);
    glob->gui->teraser = sfTexture_createFromFile("assets/Eraser.png", NULL);
    glob->gui->seraser = sfSprite_create();
    sfSprite_setTexture(glob->gui->seraser, glob->gui->teraser, sfFalse);
    sfSprite_setPosition(glob->gui->seraser, (sfVector2f) {1267, 63});
    sfSprite_setScale(glob->gui->seraser, (sfVector2f) {0.05, 0.05});
}

static void init_size_down(global_t *glob)
{
    glob->gui->size_down = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->size_down, (sfVector2f) {30, 30});
    sfRectangleShape_setOrigin(glob->gui->size_down, (sfVector2f) {15, 15});
    sfRectangleShape_setPosition(glob->gui->size_down,
        (sfVector2f) {1920 * 36 / 100, 100});
    sfRectangleShape_setFillColor(glob->gui->size_down, sfTransparent);
    sfRectangleShape_setOutlineColor(glob->gui->size_down, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->gui->size_down, 2.0f);
    glob->gui->tdown = sfTexture_createFromFile("assets/Size_down.png", NULL);
    glob->gui->sdown = sfSprite_create();
    sfSprite_setTexture(glob->gui->sdown, glob->gui->tdown, sfFalse);
    sfSprite_setPosition(glob->gui->sdown, (sfVector2f) {679, 88});
    sfSprite_setScale(glob->gui->sdown, (sfVector2f) {0.05, 0.05});
}

static void init_size_up(global_t *glob)
{
    glob->gui->size_up = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->size_up, (sfVector2f) {30, 30});
    sfRectangleShape_setOrigin(glob->gui->size_up, (sfVector2f) {15, 15});
    sfRectangleShape_setPosition(glob->gui->size_up,
        (sfVector2f) {1920 * 36 / 100, 50});
    sfRectangleShape_setFillColor(glob->gui->size_up, sfTransparent);
    sfRectangleShape_setOutlineColor(glob->gui->size_up, sfWhite);
    sfRectangleShape_setOutlineThickness(glob->gui->size_up, 2.0f);
    glob->gui->tup = sfTexture_createFromFile("assets/Size_up.png", NULL);
    glob->gui->sup = sfSprite_create();
    sfSprite_setTexture(glob->gui->sup, glob->gui->tup, sfFalse);
    sfSprite_setPosition(glob->gui->sup, (sfVector2f) {679, 38});
    sfSprite_setScale(glob->gui->sup, (sfVector2f) {0.05, 0.05});
}

void init_size_changer(global_t *glob)
{
    init_size_up(glob);
    init_size_down(glob);
}

void init_menu_bar(global_t *glob)
{
    init_file(glob);
    init_edit(glob);
    init_help(glob);
}

void init_gui(global_t *glob)
{
    init_line(glob);
    init_brush(glob);
    init_eraser(glob);
    init_size_changer(glob);
    init_menu_bar(glob);
}
