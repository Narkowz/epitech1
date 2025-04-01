/*
** EPITECH PROJECT, 2023
** initialize.c
** File description:
** initialize
*/

#include "include/my_radar.h"

window_t *initialize_window(window_t *window)
{
    sfVideoMode mode = {1920, 1080, 64};

    window = malloc(sizeof(window_t));
    window->window = sfRenderWindow_create(mode, "my_radar", sfClose, NULL);
    sfRenderWindow_setPosition(window->window, (sfVector2i){0, 0});
    window->back = sfTexture_createFromFile("./assets/back.jpg", NULL);
    window->back_sprite = sfSprite_create();
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfSprite_setTexture(window->back_sprite, window->back, sfTrue);
    window->disp_hitbox = 0;
    window->disp_sprite = 1;
    window->game_running = -1;
    window->font = sfFont_createFromFile("assets/Heavitas.ttf");
    window->pos_screen = (sfVector2f){sfRenderWindow_getSize(window->window).x
        / 2, sfRenderWindow_getSize(window->window).y / 2};
    window->end_text = sfText_create();
    window->esc = sfText_create();
    window->menu = sfText_create();
    window->space = sfText_create();
    return window;
}

void game(window_t *window, radar_t *radar, plane_t *plane)
{
    movements(radar, plane, window);
    collisions(radar, plane, window);
    protected(window, radar, plane);
    my_show_list(radar, plane, window);
    draw_timer(window);
    handle_event(window, radar, plane);
    sfRenderWindow_display(window->window);
}

void init_game(window_t **window, radar_t **radar,
    plane_t **plane, char **script)
{
    srand(time(NULL));
    (*window)->clock = sfClock_create();
    put_in_list(radar, plane, script);
    my_show_list(*radar, *plane, *window);
}

int start_game(char *av)
{
    window_t *window = initialize_window(window);
    radar_t *radar = NULL;
    plane_t *plane = NULL;
    char **script = NULL;

    script = opening_file(av);
    init_game(&window, &radar, &plane, script);
    while (sfRenderWindow_isOpen(window->window)) {
        while (window->game_running == -1 &&
            sfRenderWindow_isOpen(window->window))
            menu(window, radar, plane);
        while (test_end(window, plane) == 1 &&
            sfRenderWindow_isOpen(window->window))
            game(window, radar, plane);
        display_end(window);
        how_many(window, plane);
        handle_event(window, radar, plane);
    }
    free_list(window, radar, plane);
}
