/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** bigger
*/

#include "../include/need4stek.h"

int find_bigger(all_t *all, int bigger)
{
    int nb = 0;
    int i = 0;
    int coo_bigger = 0;
    int equal = 0;

    bigger = 0;
    for (; all->coo_lidar[i] != NULL; i++) {
        nb = atoi(all->coo_lidar[i]);
        if (nb > bigger) {
            bigger = nb;
            coo_bigger = i;
            equal = 0;
        }
        if (nb == bigger)
            equal++;
    }
    coo_bigger = coo_bigger + (int) (equal / 2);
    return coo_bigger;
}
