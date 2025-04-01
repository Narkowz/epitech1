/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** return 1 if prime 0 if not
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return 0;
    for (; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
