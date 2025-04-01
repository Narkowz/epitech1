/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** GG
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 0) {
        return (0);
    }
    while (nb % i > 0) {
        i++;
    }
    if (i == nb) {
        return (1);
    }
    return (0);
}
