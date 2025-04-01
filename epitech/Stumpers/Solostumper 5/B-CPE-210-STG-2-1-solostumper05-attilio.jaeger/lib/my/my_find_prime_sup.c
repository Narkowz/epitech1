/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** oui
*/

#include "../../include/my.h"

int my_is_prime_bis(int nb)
{
    int i = 2;

    if (nb <= 0 || nb == 1)
        return (0);
    while (i <= nb / 2){
        if (nb % i == 0)
            return (0);
        i++;
        }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int i = nb;

    if (my_is_prime_bis(i) == 1)
        return (nb);
    else {
        while (my_is_prime_bis(i) != 1)
            i++;
    }
    return (i);
}
