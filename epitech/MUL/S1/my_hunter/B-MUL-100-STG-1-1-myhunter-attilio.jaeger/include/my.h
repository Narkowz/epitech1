/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdarg.h>
#include <SFML/Graphics/Rect.h>

#ifndef MY_H_
    #define MY_H_

typedef struct initialization {
    sfRenderWindow* window;
    sfEvent event;
    sfTexture* background;
    sfSprite* back_sprite;
    sfClock *clock;
} buf_t;

typedef struct sprite_menu {
    sfTexture* playbutton;
    sfTexture* title;
    sfTexture* settings;
    sfMusic* menu_music;
    sfSprite* title_sprite;
    sfSprite* play_sprite;
    sfSprite* settings_sprite;
} sprite_menu_t;

typedef struct werewolf {
    sfTexture* wolf;
    sfSprite* wolf_sprite;
    sfMusic* battle_music;
    sfMusic* branches_song;
    int posX;
    int posY;
    sfFloatRect hitbox;
} werewolf_t;

typedef struct global {
    buf_t *buf;
    sprite_menu_t *sprite_menu;
    werewolf_t *werewolf;
} global_t;

sprite_menu_t *sprite_initialization(void);
buf_t *create_hunter(void);
werewolf_t *create_werewolf(void);
int move_rect(sfIntRect *rect, int offset, int max_value);
int draw_sprite_menu(sprite_menu_t *s_init, buf_t *buff, werewolf_t *werewolf);
int if_click_play(
    sfRenderWindow *window, sfEvent event, sprite_menu_t *sprite_menu,
    buf_t *buff);
int if_click_settings(
    sfRenderWindow *window, sfEvent event, sprite_menu_t *sprite_menu,
    buf_t *buff);
int handle_clock(sfClock *clock);
int end_game(
    buf_t *end_game, sprite_menu_t *sprite_menu, werewolf_t *werewolf);
static int speed_func(struct initialization *buf, werewolf_t *wolf);
static int start_game(buf_t *buf, werewolf_t *wolf);
static int handle_event_game(
    buf_t *buf, sprite_menu_t *sprite_menu, werewolf_t *werewolf, int *hit);
int game(buf_t *buf, sprite_menu_t *sprite_menu, werewolf_t *wolf);
void end_menu(
    buf_t *end_game, sprite_menu_t *sprite_menu, werewolf_t *werewolf);
int handle_event_menu(
    buf_t *buf, sprite_menu_t *sprite_menu, werewolf_t *werewolf);
int randrange(void);
void werewolf_hit(buf_t *buf, werewolf_t *werewolf, int *hit);
char *my_strdup(char const *src);
char *int_to_char(int value);
char *add_to_string(char *buffer, char *adding);
sfText *test_init(void);
int type(char type, va_list args);
int print(char const *str, va_list args);
int mini_printf(const char *format, ...);
void my_putchar(char c);
int my_putstr(char const *str);
void help_flag(void);
int create_window(void);

#endif /* !MY_H_ */
