/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** game
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include "./include/my.h"

sfText *test_init(void)
{
    sfFont* font = sfFont_createFromFile("content/Font.ttf");
    sfText* text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){10, 10});
    return text;
}

static int speed_func(struct initialization *buf, werewolf_t *wolf)
{
    static float speed = 15.0f;

    wolf->posX += speed;
    return wolf->posX;
}

int randrange(void)
{
    return rand() % 600 + 20;
}

static int start_game(buf_t *buf, werewolf_t *w)
{
    static int frame = 0;
    sfIntRect rect = {frame * 128, 0, 128, 128};
    sfTime elapsed = sfClock_getElapsedTime(buf->clock);

    sfSprite_setTextureRect(w->wolf_sprite, rect);
    speed_func(buf, w);
    sfSprite_setScale(w->wolf_sprite, (sfVector2f){1.7, 1.7});
    sfSprite_setPosition(w->wolf_sprite, (sfVector2f){w->posX, w->posY});
    w->hitbox = sfSprite_getGlobalBounds(w->wolf_sprite);
    sfRenderWindow_drawSprite(buf->window, buf->back_sprite, NULL);
    sfRenderWindow_drawSprite(buf->window, w->wolf_sprite, NULL);
    if (sfTime_asSeconds(elapsed) >= 0.03) {
        frame = (frame + 1) % 9;
        sfClock_restart(buf->clock);
    }
}

void werewolf_hit(buf_t *buf, werewolf_t *werewolf, int *hit)
{
    sfVector2i mouse;
    sfTime elapsed = sfClock_getElapsedTime(buf->clock);
    sfTexture* death;
    static int frame = 0;
    sfIntRect rect;

    if (buf->window)
        mouse = sfMouse_getPositionRenderWindow(buf->window);
    if (sfFloatRect_contains(&werewolf->hitbox, mouse.x, mouse.y)) {
        (*hit)++;
        werewolf->posX = -128;
        werewolf->posY = randrange();
    }
}

static int handle_event_game(
    buf_t *buf, sprite_menu_t *sprite_menu, werewolf_t *werewolf, int *hit)
{
    sfVector2i mouse;

    if (buf->window)
        mouse = sfMouse_getPositionRenderWindow(buf->window);
        if (werewolf->posX > 2000) {
            return 1;
        }
    while (sfRenderWindow_pollEvent(buf->window, &buf->event)) {
        if (buf->event.type == sfEvtClosed)
            sfRenderWindow_close(buf->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            end_game(buf, sprite_menu, werewolf);
            return 1;
        }
        if (buf->event.type == sfEvtMouseButtonPressed)
            werewolf_hit(buf, werewolf, hit);
    }
    return 0;
}

void ending_game(buf_t *buf, werewolf_t *wolf, sfText *text)
{
    sfText *end = test_init();
    sfText *escape = test_init();

    if (buf->window) {
        sfRenderWindow_clear(buf->window, sfWhite);
        sfRenderWindow_drawSprite(buf->window, buf->back_sprite, NULL);
        sfText_setPosition(text, (sfVector2f){850, 170});
        sfRenderWindow_drawText(buf->window, text, NULL);
        sfText_setString(end, "Game Over");
        sfText_setCharacterSize(end, 150);
        sfText_setPosition(end, (sfVector2f){650, 350});
        sfRenderWindow_drawText(buf->window, escape, NULL);
        sfText_setString(escape, "Press Escape to exit");
        sfText_setPosition(escape, (sfVector2f){750, 500});
        sfRenderWindow_drawText(buf->window, end, NULL);
        sfRenderWindow_drawText(buf->window, escape, NULL);
        sfRenderWindow_display(buf->window);
        sfMusic_stop(wolf->battle_music);
    }
}

int game(buf_t *buf, sprite_menu_t *sprite_menu, werewolf_t *wolf)
{
    int hit = 0;
    char *tmp = malloc(sizeof(char));
    char *hit_text = my_strdup("Score   ");
    sfText *text = test_init();
    sfText *end = test_init();

    sfMusic_stop(sprite_menu->menu_music);
    sfMusic_play(wolf->battle_music);
    while (buf->window != NULL && (buf->window)) {
        if (handle_event_game(buf, sprite_menu, wolf, &hit) == 1)
            break;
        start_game(buf, wolf);
        free(tmp);
        tmp = int_to_char(hit);
        hit_text = add_to_string(hit_text, tmp);
        sfText_setString(text, hit_text);
        sfRenderWindow_drawText(buf->window, text, NULL);
        sfRenderWindow_display(buf->window);
    }
    ending_game(buf, wolf, text);
}
