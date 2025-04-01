/*
** EPITECH PROJECT, 2024
** test_end.c
** File description:
** test_end
*/

#include "include/my_radar.h"

static void strrev(char *str)
{
    int length = my_strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int intermediate_draw(sfText **reachedText, char reachedStr[],
    window_t *window, int *reachedCount)
{
    int index = 9;
    int max = 20;

    sfText_setFont(*reachedText, window->font);
    sfText_setCharacterSize(*reachedText, 20);
    sfText_setFillColor(*reachedText, sfWhite);
    do {
        reachedStr[index] = '0' + *reachedCount % 10;
        *reachedCount /= 10;
        index++;
    } while (*reachedCount != 0 && index < (12 - 1));
    reachedStr[index] = '\0';
    strrev(reachedStr + 9);
    sfText_setString(*reachedText, reachedStr);
    sfText_setPosition(*reachedText, (sfVector2f){10.f, 10.f});
    sfRenderWindow_drawText(window->window, *reachedText, NULL);
    return index - 1;
}

void draw_counts(window_t *window)
{
    sfText *reachText = sfText_create();
    char reachStr[20] = "Reached: ";
    sfText *collideText = sfText_create();
    int index = 9;
    int collideCount = window->collide;
    char collideStr[20] = "Collided: ";

    index = intermediate_draw(&reachText, reachStr, window, &window->reached);
    sfText_setFont(collideText, window->font);
    sfText_setCharacterSize(collideText, 20);
    sfText_setFillColor(collideText, sfWhite);
    do {
        collideStr[index] = '0' + collideCount % 10;
        collideCount /= 10;
        index++;
    } while (collideCount != 0 && index < sizeof(collideStr) - 1);
    collideStr[index] = '\0';
    sfText_setString(collideText, collideStr);
    sfText_setPosition(collideText, (sfVector2f){10.f, 40.f});
    sfRenderWindow_drawText(window->window, collideText, NULL);
}

void how_many(window_t *window, plane_t *plane)
{
    plane_t *temp = plane;

    window->reached = 0;
    window->collide = 0;
    for (; temp != NULL; temp = temp->next) {
        if (temp->reached == 1)
            window->reached++;
        if (temp->collide == 1)
            window->collide++;
    }
    draw_counts(window);
    sfRenderWindow_display(window->window);
}

void display_end(window_t *window)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, window->back_sprite, 0);
    sfText_setOrigin(window->end_text, (sfVector2f){550, 100});
    sfText_setOrigin(window->esc, (sfVector2f){180, 0});
    sfText_setString(window->end_text, "Simulation Over");
    sfText_setString(window->esc, "Press ESC to exit");
    sfText_setCharacterSize(window->end_text, 100);
    sfText_setCharacterSize(window->esc, 30);
    sfText_setFont(window->end_text, window->font);
    sfText_setFont(window->esc, window->font);
    sfText_setPosition(window->end_text, window->pos_screen);
    sfText_setPosition(window->esc, (sfVector2f){window->pos_screen.x,
        window->pos_screen.y + 100});
    sfText_setFillColor(window->end_text, sfWhite);
    sfText_setFillColor(window->esc, sfWhite);
    sfRenderWindow_drawText(window->window, window->end_text, 0);
    sfRenderWindow_drawText(window->window, window->esc, 0);
}

int test_end(window_t *window, plane_t *plane)
{
    plane_t *temp = plane;

    for (; temp != NULL; temp = temp->next)
        if (temp->collide == 0 && temp->reached == 0)
            return 1;
    free(temp);
    return 0;
}
