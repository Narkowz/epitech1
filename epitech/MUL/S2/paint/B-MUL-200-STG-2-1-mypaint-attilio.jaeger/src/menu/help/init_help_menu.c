/*
** EPITECH PROJECT, 2024
** draw_help_menu.c
** File description:
** draw_help_menu
*/

#include "../../../include/my_paint.h"

static void init_header(global_t *glob)
{
    glob->menu->helptxt = sfText_create();
    glob->menu->helprect = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->helprect, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->helprect, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->helprect,
        (sfVector2f) {156, 12});
    sfRectangleShape_setFillColor(glob->menu->helprect, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->helprect, 1.0f);
    sfText_setFont(glob->menu->helptxt, glob->menu->font);
    sfText_setString(glob->menu->helptxt, "Help");
    sfText_setCharacterSize(glob->menu->helptxt, 20);
    sfText_setPosition(glob->menu->helptxt, (sfVector2f) {135, 0});
    sfText_setFillColor(glob->menu->helptxt, sfBlack);
}

static void init_about(global_t *glob)
{
    glob->menu->abouttxt = sfText_create();
    glob->menu->about = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->about, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->about, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->about,
        (sfVector2f) {156, 35});
    sfRectangleShape_setFillColor(glob->menu->about, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->about, 1.0f);
    sfText_setFont(glob->menu->abouttxt, glob->menu->font);
    sfText_setString(glob->menu->abouttxt, "About");
    sfText_setCharacterSize(glob->menu->abouttxt, 20);
    sfText_setPosition(glob->menu->abouttxt, (sfVector2f) {129, 22});
    sfText_setFillColor(glob->menu->abouttxt, sfBlack);
}

static void init_aled(global_t *glob)
{
    glob->menu->aledtxt = sfText_create();
    glob->menu->aled = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->menu->aled, (sfVector2f) {60, 20});
    sfRectangleShape_setOrigin(glob->menu->aled, (sfVector2f) {30, 10});
    sfRectangleShape_setPosition(glob->menu->aled,
        (sfVector2f) {156, 58});
    sfRectangleShape_setFillColor(glob->menu->aled, sfTransparent);
    sfRectangleShape_setOutlineThickness(glob->menu->aled, 1.0f);
    sfText_setFont(glob->menu->aledtxt, glob->menu->font);
    sfText_setString(glob->menu->aledtxt, "Help");
    sfText_setCharacterSize(glob->menu->aledtxt, 20);
    sfText_setPosition(glob->menu->aledtxt, (sfVector2f) {135, 44});
    sfText_setFillColor(glob->menu->aledtxt, sfBlack);
}

static void set_string(global_t *glob)
{
    sfText_setString(glob->gui->about, "Paint\n\nAn Epitech Project.\
    Made in solo by Jaeger Attilio.\n\n\n\tTime duration :\t\t\t\t\t\t\t\t\t\
    Complexity :\n 24.02.24 - 15.03.24\t\t\t\t\t\t\t\t \t\t7 / 10\n\n\t\t\
    \t\t\t\t\t\t\tLiked it at :\n\t\t\t\t\t\t\t\t\t\t\t8 / 10");
}

void init_about_me(global_t *glob)
{
    sfVector2u s = sfRenderWindow_getSize(glob->window);

    glob->gui->about = sfText_create();
    glob->gui->aboutrect = sfRectangleShape_create();
    sfRectangleShape_setSize(glob->gui->aboutrect, (sfVector2f) {500, 300});
    sfRectangleShape_setOrigin(glob->gui->aboutrect, (sfVector2f) {250, 150});
    sfRectangleShape_setPosition(glob->gui->aboutrect,
        (sfVector2f) {s.x / 2, s.y / 2});
    sfRectangleShape_setFillColor(glob->gui->aboutrect, (sfColor)
        {255, 204, 255, 255});
    sfRectangleShape_setOutlineColor(glob->gui->aboutrect, sfBlack);
    sfRectangleShape_setOutlineThickness(glob->gui->aboutrect, 1.0f);
    sfText_setFont(glob->gui->about, glob->menu->font);
    sfText_setCharacterSize(glob->gui->about, 20);
    set_string(glob);
    sfText_setPosition(glob->gui->about, (sfVector2f) {(s.x / 2) - 240,
        (s.y / 2) - 130});
    sfText_setFillColor(glob->gui->about, sfBlack);
}

void init_help(global_t *glob)
{
    glob->menu->hisopen = sfFalse;
    glob->gui->isabout = sfFalse;
    init_header(glob);
    init_about(glob);
    init_aled(glob);
    init_about_me(glob);
    init_aled_wind(glob);
}
