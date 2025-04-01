/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int i = 0;

    i = *a;
    *a = *b;
    *b = i;
}
