/*
** EPITECH PROJECT, 2023
** handle_event.c
** File description:
** handle_event
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include "./include/my.h"

void end_menu(
    buf_t *end_game, sprite_menu_t *sprite_menu, werewolf_t *werewolf)
{
    if (werewolf->wolf_sprite) {
        sfSprite_destroy(werewolf->wolf_sprite);
    }
    if (sprite_menu->title_sprite) {
        sfSprite_destroy(sprite_menu->title_sprite);
    }
    if (sprite_menu->settings_sprite) {
        sfSprite_destroy(sprite_menu->settings_sprite);
    }
    if (sprite_menu->play_sprite) {
        sfSprite_destroy(sprite_menu->play_sprite);
    }
}

int handle_event_menu(
    buf_t *buf, sprite_menu_t *sprite_menu, werewolf_t *werewolf)
{
    while (sfRenderWindow_pollEvent(buf->window, &buf->event)) {
        if (buf->event.type == sfEvtClosed)
            sfRenderWindow_close(buf->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            end_game(buf, sprite_menu, werewolf);
            return 1;
        }
        if (if_click_play(buf->window, buf->event, sprite_menu, buf) == 5) {
            sfMusic_play(werewolf->branches_song);
            return 5;
        }
    }
}
