/*
** EPITECH PROJECT, 2023
** my_hunter.c
** File description:
** my_hunter
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include <stdio.h>
#include "./include/my.h"

int move_rect(sfIntRect *rect, int offset, int max_value)
{
    int width = rect->left + offset;

    if (width > max_value)
        width = 0;
    rect->left = width;
    return width;
}

int draw_sprite_menu(sprite_menu_t *s_init, buf_t *buff, werewolf_t *werewolf)
{
    sfText *title = test_init();

    sfRenderWindow_clear(buff->window, sfBlack);
    sfRenderWindow_drawSprite(buff->window, buff->back_sprite, NULL);
    sfRenderWindow_drawSprite(buff->window, s_init->play_sprite, NULL);
    sfText_setCharacterSize(title, 180);
    sfText_setString(title, "Werewolf hunt");
    sfText_setPosition(title, (sfVector2f){450, 150});
    sfRenderWindow_drawText(buff->window, title, NULL);
    sfRenderWindow_display(buff->window);
    return (0);
}

int if_click_play(
    sfRenderWindow *window, sfEvent event,
    sprite_menu_t *sprite_menu, buf_t *buff)
{
    sfVector2i mouse;

    if (window)
        mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > 808 && mouse.x < 1093 && mouse.y > 445 && mouse.y < 522) {
        if (event.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_display(window);
            return 5;
        }
    } else {
        return 10;
    }
}

int end_game(buf_t *end_game, sprite_menu_t *sprite_menu, werewolf_t *werewolf)
{
    if (werewolf->wolf_sprite && werewolf->wolf)
        sfSprite_destroy(werewolf->wolf_sprite);
    if (sprite_menu->title_sprite && sprite_menu->title)
        sfSprite_destroy(sprite_menu->title_sprite);
    if (sprite_menu->settings_sprite && sprite_menu->settings)
        sfSprite_destroy(sprite_menu->settings_sprite);
    if (sprite_menu->play_sprite && sprite_menu->playbutton)
        sfSprite_destroy(sprite_menu->play_sprite);
    if (end_game->back_sprite && end_game->background)
        sfSprite_destroy(end_game->back_sprite);
    if (end_game->clock)
        sfClock_destroy(end_game->clock);
    if (sprite_menu->menu_music)
        sfMusic_stop(sprite_menu->menu_music);
    if (werewolf->battle_music)
        sfMusic_stop(werewolf->battle_music);
    if (end_game->window)
        sfRenderWindow_destroy(end_game->window);
    end_game->window = NULL;
}
