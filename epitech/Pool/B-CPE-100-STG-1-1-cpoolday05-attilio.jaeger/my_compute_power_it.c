/*
** EPITECH PROJECT, 2023
** my_compute_power_it.c
** File description:
** power it
*/

int my_compute_power_it(int nb, int p)
{
    int i = 0;
    long result = 1;

    for (; i < p ; i++) {
        result *= nb;
    }
    if (p < 0) {
        result = 0;
    }
    if (result > 2147483647) {
        result = 0;
    }
    return result;
}
