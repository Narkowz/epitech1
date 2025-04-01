/*
** EPITECH PROJECT, 2023
** my_compute_factorial_it.c
** File description:
** compute factorial it
*/

int my_compute_factorial_it(int nb)
{
    int i = nb;
    int res = 1;

    if (nb > 12) {
        return (0);
    }
    if (nb == 0) {
        return (1);
    }
    if (nb < 0) {
        return (0);
    }
    iterative(nb, &i, &res);
    return (res);
}

int iterative(int nb, int *i, int *res)
{
    for (*i = 2; *i <= nb; ++(*i)) {
        *res *= *i;
    }
}
