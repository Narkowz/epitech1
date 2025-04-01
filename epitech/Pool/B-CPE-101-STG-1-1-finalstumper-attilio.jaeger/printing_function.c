/*
** EPITECH PROJECT, 2023
** Printing_function
** File description:
** printing function
*/

#include <unistd.h>
#include "./include/rush3.h"

int printing_function(int count_y, int count_x)
{
    my_put_nbr(count_x);
    my_putchar(' ');
    my_put_nbr(count_y);
}
