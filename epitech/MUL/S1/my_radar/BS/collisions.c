/*
** EPITECH PROJECT, 2023
** collisions.c
** File description:
** collisions
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
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
#include <time.h>
#include "my.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle;

    circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 1);
    return circle;
}

int is_intersecting_circles(linked_list_t *origin)
{
    linked_list_t *temp = origin;
    sfVector2f temp_pos;
    sfVector2f list_pos;
    float temp_radius;
    float list_radius;
    sfVector2f c_temp;
    sfVector2f c_list;

    while (temp != NULL) {
        sfCircleShape_setFillColor(temp->circle, sfBlack);
        temp = temp->next;
    }
    temp = origin;
    while (origin != NULL) {
        temp = origin->next;
        while (temp != NULL) {
            temp_pos = sfCircleShape_getPosition(temp->circle);
            list_pos = sfCircleShape_getPosition(origin->circle);
            temp_radius = sfCircleShape_getRadius(temp->circle);
            list_radius = sfCircleShape_getRadius(origin->circle);
            c_temp = (sfVector2f){(temp_pos.x + temp_radius), (temp_pos.y + temp_radius)};
            c_list = (sfVector2f){(list_pos.x + list_radius), (list_pos.y + list_radius)};
            if ((power_rec((c_temp.x - c_list.x), 2) + power_rec((c_temp.y - c_list.y), 2)) <= power_rec((temp_radius + list_radius), 2)) {
                sfCircleShape_setFillColor(temp->circle, sfWhite);
                sfCircleShape_setFillColor(origin->circle, sfWhite);
            }
            temp = temp->next; 
        }
        origin = origin->next;
    }
    return 0;
}

void color_top_left(linked_list_t *list, window_t *window, corner_t *corner)
{
    linked_list_t *top_list = list;
    sfVector2f pos;

    while (top_list != NULL) {
        pos = sfCircleShape_getPosition(top_list->circle);
        if ((pos.x < corner->area.width && pos.x > 0) && (pos.y < corner->area.height && pos.y > 0))
            sfCircleShape_setFillColor(top_list->circle, sfRed);
        if ((pos.x > corner->area.width && pos.x < corner->area.width * 2) && (pos.y < corner->area.height && pos.y > 0))
            sfCircleShape_setFillColor(top_list->circle, sfBlue);
        if ((pos.x < corner->area.width && pos.x > 0) && (pos.y > corner->area.height && pos.y < corner->area.height * 2))
            sfCircleShape_setFillColor(top_list->circle, sfYellow);
        if ((pos.x > corner->area.width && pos.x < corner->area.width * 2) && (pos.y > corner->area.height && pos.y < corner->area.height * 2))
            sfCircleShape_setFillColor(top_list->circle, sfGreen);
        top_list = top_list->next;
    }
}

void print_framerate ()
{
    static int first = 1;
    static sfClock * clock;
    static int fps = 0;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock) ;
    if (sfTime_asSeconds(elapsed) >= 1) {
        printf("%3d FPS \r", fps);
        fflush(stdout);
        fps = 0;
        sfClock_restart (clock);
    }
    else
        fps++;
}

sfVector2f put_in_list(linked_list_t **list)
{
    float radius = rand() % 50 + 15;
    sfVector2f position = {rand() % 1820 + 10, rand() % 980 + 10};
    linked_list_t *temp = malloc(sizeof(struct linked_list));

    temp->circle = create_circle(position, radius);
    temp->next = *list;
    *list = temp;
    return position;
}

void my_show_list(linked_list_t *list, window_t *window, sfVector2f position)
{
    linked_list_t *tmp;

    tmp = list;
        sfRenderWindow_clear(window->window, sfBlack);
    while (tmp != NULL) {
        position = sfCircleShape_getPosition(tmp->circle);
        sfCircleShape_setPosition(tmp->circle, (sfVector2f){position.x + rand() % 3 - 1,position.y + rand() % 3 - 1  });
        sfRenderWindow_drawCircleShape(window->window, tmp->circle, 0);
        tmp = tmp->next;
    }
}

void free_list(linked_list_t *list, window_t *window)
{
    linked_list_t *temp = list;

    while (list != NULL) {
        temp = list;
        list = list->next;
        sfCircleShape_destroy(temp->circle);
        free(temp);
    }
    free(list);
    free(window);
}

void handle_event(linked_list_t *list, window_t *window)
{   
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)){
            sfRenderWindow_close(window->window);
            sfRenderWindow_destroy(window->window);
            free_list(list, window);
        }
    }
}

void initialize_screen(linked_list_t *list, window_t *window, corner_t *corner)
{
    sfVector2u size = sfRenderWindow_getSize(window->window);
    corner->area.width = size.x / 2;
    corner->area.height = size.y / 2;
}


void main(void)
{
    linked_list_t *list = NULL;
    window_t *window = malloc(sizeof(window_t));
    corner_t *corner = malloc(sizeof(corner_t));
    sfVideoMode mode = {1920, 1080, 64};
    sfVector2f position;
    int limit = 5000;

    srand(time(NULL));
    window->window = sfRenderWindow_create(mode, "radar", sfClose, NULL);
    for (int i = 0; i != limit; i++) {
        position = put_in_list(&list);
    }
    initialize_screen(list, window, corner);
    while (sfRenderWindow_isOpen(window->window)) {
        print_framerate();
        handle_event(list, window);
        is_intersecting_circles(list);
        color_top_left(list, window, corner);
        my_show_list(list, window, position);
        sfRenderWindow_display(window->window);
    }
    if (list) {
        sfRenderWindow_destroy(window->window);
        free_list(list, window);
    }
}
