/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** power rec
*/

#include "../../include/my.h"

int my_compute_power_rec(int nb, int power)
{
    if (power < 0) {
        return (0);
    }
    if (power == 0) {
        return (1);
    }
    if (power == 1) {
        return (nb);
    }
    if (power > 0) {
        return (my_compute_power_rec(nb, power - 1) * nb);
    }
}
