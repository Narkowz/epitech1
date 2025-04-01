/*
** EPITECH PROJECT, 2024
** test_protection.c
** File description:
** test_protection
*/

#include "include/my_radar.h"

int test_protection(sfVector2f circlePosition, float circleRadius,
    sfFloatRect rectBounds)
{
    float closestX = circlePosition.x;
    float closestY = circlePosition.y;
    float distanceX;
    float distanceY;
    float distanceSquared;

    if (circlePosition.x < rectBounds.left) {
        closestX = rectBounds.left;
    } else if (circlePosition.x > rectBounds.left + rectBounds.width) {
        closestX = rectBounds.left + rectBounds.width;
    }
    if (circlePosition.y < rectBounds.top) {
        closestY = rectBounds.top;
    } else if (circlePosition.y > rectBounds.top + rectBounds.height) {
        closestY = rectBounds.top + rectBounds.height;
    }
    distanceX = circlePosition.x - closestX;
    distanceY = circlePosition.y - closestY;
    distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    return distanceSquared < (circleRadius * circleRadius) ? 1 : 0;
}

void intermediate(sfVector2f circlePosition, float circleRadius,
    sfFloatRect rectBounds, plane_t *temp)
{
    rectBounds = sfRectangleShape_getGlobalBounds(temp->hitbox);
    if (test_protection(circlePosition, circleRadius, rectBounds) == 1)
        temp->protected = 1;
    else
        temp->protected = 0;
}

void protected(window_t *window, radar_t *radar, plane_t *plane)
{
    sfVector2f circlePosition;
    float circleRadius;
    sfFloatRect rectBounds;
    plane_t *temp = plane;
    radar_t *temp_t = radar;

    for (; temp_t != NULL; temp_t = temp_t->next) {
        circlePosition = sfCircleShape_getPosition(temp_t->circle);
        circleRadius = sfCircleShape_getRadius(temp_t->circle);
        circlePosition = (sfVector2f){circlePosition.x + circleRadius,
            circlePosition.y + circleRadius};
        for (; temp != NULL; temp = temp->next)
            intermediate(circlePosition, circleRadius, rectBounds, temp);
    }
}
