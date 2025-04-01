/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** e
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 0 || nb == 1)
        return (0);
    while (i <= nb / 2) {
        if (nb % i == 0)
            return (0);
        i++;
        }
    return (1);
}
