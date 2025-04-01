/*
** EPITECH PROJECT, 2024
** set_real_size.c
** File description:
** set_real_size
*/

#include "include/my_radar.h"

sfVector2f calcul_size(sfVector2f pos, int choice)
{
    const sfVector2f tower = {512, 512};
    const float scale_tower = 0.15;
    const sfVector2f plane = {285, 268};
    const float scale_plane = 0.3;
    sfVector2f res = {0, 0};

    if (choice == 0) {
        res.x = pos.x + ((plane.x * scale_plane) / 2);
        res.y = pos.y + ((plane.y * scale_plane) / 2);
    }
    if (choice == 1) {
        res.x = pos.x - ((tower.x * scale_tower) / 2);
        res.y = pos.y - ((tower.y * scale_tower) / 2);
    }
    return res;
}
