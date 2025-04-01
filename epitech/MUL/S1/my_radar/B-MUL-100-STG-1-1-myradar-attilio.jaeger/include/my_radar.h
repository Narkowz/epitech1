/*
** EPITECH PROJECT, 2023
** my_radar.h
** File description:
** my_radar
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Transform.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_
    #define M_PI 3.14159265358979323846


typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *back;
    sfSprite *back_sprite;
    sfClock *clock;
    sfTime time;
    sfText *end_text;
    sfText *esc;
    sfText *menu;
    sfText *space;
    sfFont *font;
    sfClock *timer;
    sfVector2f pos_screen;
    int collide;
    int reached;
    int disp_hitbox;
    int disp_sprite;
    int game_running;
} window_t;

typedef struct radar_s {
    sfTexture *tower;
    sfSprite *tower_sprite;
    sfVector2i pos;
    sfCircleShape *circle;
    float radius;
    struct radar_s *next;
} radar_t;

typedef struct plane_s {
    sfTexture *plane;
    sfSprite *plane_sprite;
    sfVector2f take_off;
    sfVector2i land;
    sfVector2f curr_pos;
    sfRectangleShape *hitbox;
    float rotation;
    int delay;
    int reached;
    int collide;
    int protected;
    float speed;
    struct plane_s *next;
} plane_t;

void print_usage(void);
void handle_event(window_t *window, radar_t *radar, plane_t *plane);
window_t *initialize_window(window_t *window);
int start_game(char *av);
void put_in_list(radar_t **radar, plane_t **plane, char **script);
void my_show_list(radar_t *radar, plane_t *plane, window_t *window);
void free_list(window_t *window, radar_t *radar, plane_t *plane);
void movements(radar_t *radar, plane_t *plane, window_t *window);
char **opening_file(char *path);
int allowed_file(char *path);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
float extract_number(char *str, int spaces);
sfVector2f calcul_size(sfVector2f pos, int choice);
void plane_two(radar_t **temp);
int get_time(window_t *window);
void print_framerate(void);
int collisions(radar_t *radar, plane_t *plane, window_t *window);
int power_rec(int nb, int power);
int test_end(window_t *window, plane_t *plane);
void display_end(window_t *window);
void menu(window_t *window, radar_t *radar, plane_t *plane);
void protected(window_t *window, radar_t *radar, plane_t *plane);
void how_many(window_t *window, plane_t *plane);
void draw_timer(window_t *window);
int type(char type, va_list args);
int print(char const *str, va_list args);
int mini_printf(const char *format, ...);
void my_putchar(char c);
int my_putstr(char const *str);

#endif /* !MY_RADAR_H_ */
