/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** find the prime
*/

int my_is_prime_bis(int nb)
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

int my_find_prime_sup(int nb)
{
    int i = my_is_prime_bis(nb);

    if (i == 1)
        return (nb);
    return (my_find_prime_sup(nb + 1));
}
