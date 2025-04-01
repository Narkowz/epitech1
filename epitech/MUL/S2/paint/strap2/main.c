/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "my.h"

int click_button(window_t *window, struct button_s **button)
{
    sfVector2i mouse;
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds((*button)->rect);

    if (window->window)
        mouse = sfMouse_getPositionRenderWindow(window->window);
    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) == 1) {
        sfRectangleShape_setFillColor((*button)->rect, sfYellow);
        (*button)->state = 3;
        return 1;
    }
    return 0;
}


int press_button(window_t *window, button_t **button)
{
    sfVector2i mouse;
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds((*button)->rect);

    if (window->window)
        mouse = sfMouse_getPositionRenderWindow(window->window);
    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) == 1) {
        sfRectangleShape_setFillColor((*button)->rect, sfBlue);
        (*button)->state = 2;
        return 1;
    }
    return 0;
}


int hover_button(window_t *window, button_t **button)
{
    sfVector2i mouse;
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds((*button)->rect);

    if (window->window)
        mouse = sfMouse_getPositionRenderWindow(window->window);
    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) == 1 && ((*button)->state != 2 || (*button)->state != 3)) {
        sfRectangleShape_setFillColor((*button)->rect, sfRed);
        (*button)->state = HOVER;
        return 1;
    }
    sfRectangleShape_setFillColor((*button)->rect, sfMagenta);
    return 0;
}

window_t *init_window(window_t *window)
{
    sfVideoMode mode = {1920, 1080, 64};

    window = malloc(sizeof(window_t));
    window->window = sfRenderWindow_create(mode, "Paint", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_setPosition(window->window, (sfVector2i){0, 0});
    return window;
}

button_t *init_button(button_t *button, window_t *window)
{
    button = malloc(sizeof(button_t));
    button->rect = sfRectangleShape_create();
    button->click_button = &click_button;
    button->press_button = &press_button;
    button->hover_button = &hover_button;
    button->state = 0;
    sfRectangleShape_setSize(button->rect, (sfVector2f) {200, 75});
    sfRectangleShape_setOrigin(button->rect, (sfVector2f) {200 / 2, 75 / 2});
    sfRectangleShape_setPosition(button->rect, (sfVector2f) {400, 500});
    sfRectangleShape_setFillColor(button->rect, sfMagenta);
    return button;
}

int main(void)
{
    window_t *window = init_window(window);
    button_t *button = init_button(button, window);
    
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &window->event)) {
            if (window->event.type == sfEvtClosed)
                sfRenderWindow_close(window->window);
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window->window);
            if (window->event.type == sfEvtMouseMoved)
                button->hover_button(window, &button);
            if (window->event.type == sfEvtMouseButtonReleased)
                button->click_button(window, &button);
            if (window->event.type == sfEvtMouseButtonPressed)
                button->press_button(window, &button);
        }
        sfRenderWindow_drawRectangleShape(window->window, button->rect, 0);
        sfRenderWindow_display(window->window);
    }
    sfRectangleShape_destroy(button->rect);
    sfRenderWindow_destroy(window->window);
}
