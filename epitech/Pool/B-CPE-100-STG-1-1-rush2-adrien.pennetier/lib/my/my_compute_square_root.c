/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    while (i * i <= nb) {
        if (i * i == nb) {
            return i;
        }
        i++;
    }
    return 0;
}
