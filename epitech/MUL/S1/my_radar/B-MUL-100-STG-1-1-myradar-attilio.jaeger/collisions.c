/*
** EPITECH PROJECT, 2024
** collisions.c
** File description:
** collisions
*/

#include "include/my_radar.h"

int is_intersects(sfFloatRect rect1, sfFloatRect rect2)
{
    return (rect1.left < rect2.left + rect2.width &&
            rect1.left + rect1.width > rect2.left &&
            rect1.top < rect2.top + rect2.height &&
            rect1.top + rect1.height > rect2.top);
}

int check_collision(plane_t *plane1, plane_t *plane2)
{
    sfFloatRect pos1 = sfRectangleShape_getGlobalBounds(plane1->hitbox);
    sfFloatRect pos2 = sfRectangleShape_getGlobalBounds(plane2->hitbox);

    if (is_intersects(pos1, pos2) && !plane1->protected &&
        !plane2->protected) {
        plane1->collide = 1;
        plane2->collide = 1;
    }
}

int collisions(radar_t *radar, plane_t *plane, window_t *window)
{
    plane_t *temp = plane;
    plane_t *temp_two = plane;

    temp_two = temp_two->next;
    for (; temp != NULL; temp = temp->next) {
        for (; temp_two != NULL; temp_two = temp_two->next) {
            check_collision(temp, temp_two);
        }
    }
    return 0;
}
