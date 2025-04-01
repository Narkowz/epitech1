/*
** EPITECH PROJECT, 2023
** my_compute_factorial_rec.c
** File description:
** factorial recursive
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0) {
        return (1);
    }
    if (nb < 0 || nb > 12) {
        return (0);
    }
    while (nb > 0) {
        return ((nb *my_compute_factorial_rec(nb - 1)));
    }
}
