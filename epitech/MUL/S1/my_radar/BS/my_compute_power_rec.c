/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** power rec
*/

float power_rec(float nb, float power)
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
        return (power_rec(nb, power - 1) * nb);
    }
}
