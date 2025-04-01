/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** my_swap
*/

int my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
