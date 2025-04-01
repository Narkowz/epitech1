/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** Negative or positive digits
*/

#include "../../include/my.h"

int my_isneg(int nb)
{
    if (nb >= 0){
        my_putchar('P', 1);
    } else {
        my_putchar('N', 1);
    }
}
