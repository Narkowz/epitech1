/*
** EPITECH PROJECT, 2024
** handle_event.c
** File description:
** handle_event
*/

#include "../include/my_paint.h"

void handle_event(global_t *glob)
{
    while (sfRenderWindow_pollEvent(glob->window, &glob->event)) {
        if (glob->event.type == sfEvtClosed)
            sfRenderWindow_close(glob->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(glob->window);
        if (glob->event.type == sfEvtMouseMoved)
        hover_function(glob);
        event_click(glob);
    }
}
