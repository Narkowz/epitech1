/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** compute power with a recursive function
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 0)
        nb = nb * my_compute_power_rec(nb, p - 1);
    return (nb);
}
