/*
** EPITECH PROJECT, 2023
** movements.c
** File description:
** movements
*/

#include <math.h>
#include "include/my_radar.h"

int test_reached(sfVector2f *nPos, sfVector2i tPos, float spd)
{
    if (sqrt(pow((*nPos).x - tPos.x, 2) + pow((*nPos).y - tPos.y, 2)) <= spd) {
        (*nPos).x = tPos.x;
        (*nPos).y = tPos.y;
        return 1;
    }
}

int move_to(
    plane_t *temp, sfVector2f currentPos, sfVector2i tPos, float speed)
{
    sfVector2f direction;
    sfVector2f newPos;
    float dist;

    direction.x = tPos.x - currentPos.x;
    direction.y = tPos.y - currentPos.y;
    dist = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (dist > 2) {
        direction.x /= dist;
        direction.y /= dist;
    }
    newPos.x = currentPos.x + direction.x * speed;
    newPos.y = currentPos.y + direction.y * speed;
    if (test_reached(&newPos, tPos, speed) == 1)
        return 1;
    sfSprite_setPosition(temp->plane_sprite, newPos);
    sfRectangleShape_setPosition(temp->hitbox, newPos);
    return 0;
}

void movements(radar_t *radar, plane_t *plane, window_t *window)
{
    sfVector2f pos;
    sfVector2i coo;
    plane_t *temp = plane;
    float dx;
    float dy;

    for (; temp != NULL; temp = temp->next) {
        if (temp->delay > get_time(window))
            continue;
        pos = sfSprite_getPosition(temp->plane_sprite);
        coo = temp->land;
        dx = coo.x - pos.x;
        dy = coo.y - pos.y;
        temp->rotation = atan2f(dy, dx) * 180 / M_PI;
        sfSprite_setRotation(temp->plane_sprite, temp->rotation);
        temp->reached = move_to(temp, pos, coo, temp->speed / 2);
    }
    plane = temp;
    free(temp);
}
