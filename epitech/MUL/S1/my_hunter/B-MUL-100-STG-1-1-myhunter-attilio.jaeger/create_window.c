/*
** EPITECH PROJECT, 2023
** create_window.c
** File description:
** create_window
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include <stdlib.h>
#include <time.h>
#include "./include/my.h"

sprite_menu_t *sprite_initialization(void)
{
    struct sprite_menu *s_init = malloc(sizeof(struct sprite_menu));

    s_init->menu_music = sfMusic_createFromFile("content/Menu_song.ogg");
    s_init->playbutton = sfTexture_createFromFile("content/P_b.png", NULL);
    s_init->title = sfTexture_createFromFile("content/my_hunter.png", NULL);
    s_init->settings = sfTexture_createFromFile("content/S_b.png", NULL);
    s_init->title_sprite = sfSprite_create();
    s_init->play_sprite = sfSprite_create();
    s_init->settings_sprite = sfSprite_create();
    sfSprite_setTexture(s_init->play_sprite, s_init->playbutton, sfTrue);
    sfSprite_setTexture(s_init->title_sprite, s_init->title, sfTrue);
    sfSprite_setTexture(s_init->settings_sprite, s_init->settings, sfTrue);
    sfSprite_scale(s_init->play_sprite, (sfVector2f){0.33, 0.33});
    sfSprite_setPosition(s_init->play_sprite, (sfVector2f){800, 440});
    sfSprite_scale(s_init->title_sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(s_init->title_sprite, (sfVector2f){1475, 0});
    sfSprite_scale(s_init->settings_sprite, (sfVector2f){0.33, 0.33});
    sfSprite_setPosition(s_init->settings_sprite, (sfVector2f){800, 530});
    sfMusic_setLoop(s_init->menu_music, sfTrue);
    return (s_init);
}

buf_t *create_hunter(void)
{
    struct initialization *buff;
    sfVideoMode mode = {1920, 817, 64};
    sfEvent event;

    buff = malloc(sizeof(struct initialization));
    buff->event = event;
    buff->window = sfRenderWindow_create(mode, "Werewolf hunt", sfClose, NULL);
    buff->background = sfTexture_createFromFile("./content/Back.jpg", NULL);
    buff->back_sprite = sfSprite_create();
    sfSprite_setTexture(buff->back_sprite, buff->background, sfTrue);
    return (buff);
}

werewolf_t *create_werewolf(void)
{
    struct werewolf *buff;
    sfFloatRect hitbox;

    buff = malloc(sizeof(struct werewolf));
    buff->posX = -400;
    buff->posY = randrange();
    buff->wolf = sfTexture_createFromFile("./content/Werewolf_Run.png", NULL);
    buff->wolf_sprite = sfSprite_create();
    sfSprite_setTexture(buff->wolf_sprite, buff->wolf, sfTrue);
    hitbox = sfSprite_getGlobalBounds(buff->wolf_sprite);
    buff->hitbox = hitbox;
    buff->battle_music = sfMusic_createFromFile("content/Battle_song.ogg");
    sfMusic_setLoop(buff->battle_music, sfTrue);
    buff->branches_song = sfMusic_createFromFile("content/Branches.ogg");
    return (buff);
}

int create_window(void)
{
    buf_t *buf = create_hunter();
    sprite_menu_t *s_menu = sprite_initialization();
    werewolf_t *werewolf = create_werewolf();

    sfRenderWindow_setFramerateLimit(buf->window, 60);
    buf->clock = sfClock_create();
    draw_sprite_menu(s_menu, buf, werewolf);
    sfMusic_play(s_menu->menu_music);
    while (buf->window != NULL && (buf->window) &&
    sfRenderWindow_isOpen(buf->window)) {
        if (handle_event_menu(buf, s_menu, werewolf) == 5)
            game(buf, s_menu, werewolf);
    }
    sfMusic_stop(s_menu->menu_music);
    return 0;
}
