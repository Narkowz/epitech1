/*
** EPITECH PROJECT, 2024
** palindrome.c
** File description:
** palindrome
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Error: missing arguments.", 25);
        write(2, "\n", 1);
        return 84;
    } else
        return find_palindrome(av[1]);
    return 84;
}
