/*
** EPITECH PROJECT, 2023
** put_in_list.c
** File description:
** put_in_list
*/

#include "include/my_radar.h"

plane_t *add_hitbox(plane_t *temp, sfVector2f pos_plane)
{
    temp->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(temp->hitbox, (sfVector2f){285, 268});
    sfRectangleShape_setOrigin(temp->hitbox, (sfVector2f){285 / 2, 268 / 2});
    sfRectangleShape_setScale(temp->hitbox, (sfVector2f){0.07, 0.075});
    sfRectangleShape_setFillColor(temp->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(temp->hitbox, sfWhite);
    sfRectangleShape_setOutlineThickness(temp->hitbox, 10);
    sfRectangleShape_setPosition(temp->hitbox, pos_plane);
    return temp;
}

void put_plane(plane_t **plane, char *script)
{
    sfVector2f pos_plane =
        {extract_number(script, 1), extract_number(script, 2)};
    plane_t *temp = malloc(sizeof(plane_t));

    temp->plane = sfTexture_createFromFile("./assets/plane.png", NULL);
    temp->plane_sprite = sfSprite_create();
    sfSprite_setOrigin(temp->plane_sprite, (sfVector2f){285 / 2, 268 / 2});
    sfSprite_setTexture(temp->plane_sprite, temp->plane, sfTrue);
    sfSprite_setPosition(temp->plane_sprite, pos_plane);
    sfSprite_setScale(temp->plane_sprite, (sfVector2f){0.07, 0.075});
    temp->land.x = extract_number(script, 3);
    temp->land.y = extract_number(script, 4);
    temp->speed = extract_number(script, 5);
    temp->reached = 0;
    temp->collide = 0;
    temp->protected = 0;
    temp->delay = extract_number(script, 6);
    temp = add_hitbox(temp, pos_plane);
    temp->next = *plane;
    *plane = temp;
}

void put_tower(radar_t **radar, char *script)
{
    radar_t *temp = malloc(sizeof(radar_t));
    sfVector2f pos_tower =
        {extract_number(script, 1), extract_number(script, 2)};
    sfVector2f pos_circle = {0, 0};

    temp->circle = sfCircleShape_create();
    temp->tower = sfTexture_createFromFile("./assets/tower.png", NULL);
    temp->tower_sprite = sfSprite_create();
    temp->radius = (extract_number(script, 3) / 100) * 1920;
    plane_two(&temp);
    sfSprite_setPosition(temp->tower_sprite, pos_tower);
    pos_circle = (sfVector2f)
        {pos_tower.x - temp->radius, pos_tower.y - temp->radius};
    sfCircleShape_setPosition(temp->circle, pos_circle);
    sfSprite_setScale(temp->tower_sprite, (sfVector2f){0.039, 0.039});
    temp->next = *radar;
    *radar = temp;
}

void plane_two(radar_t **temp)
{
    sfSprite_setOrigin((*temp)->tower_sprite, (sfVector2f){512 / 2, 512 / 2});
    sfSprite_setTexture((*temp)->tower_sprite, (*temp)->tower, sfTrue);
    sfCircleShape_setRadius((*temp)->circle, (*temp)->radius);
    sfCircleShape_setFillColor((*temp)->circle, sfTransparent);
    sfCircleShape_setOutlineColor((*temp)->circle, sfWhite);
    sfCircleShape_setOutlineThickness((*temp)->circle, 1);
}

void put_in_list(radar_t **radar, plane_t **plane, char **script)
{
    for (int i = 0; script[i] != NULL; i++) {
        if (script[i][0] == 'T')
            put_tower(radar, script[i]);
        if (script[i][0] == 'A')
            put_plane(plane, script[i]);
    }
}
