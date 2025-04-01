/*
** EPITECH PROJECT, 2023
** put nbr
** File description:
** printing numbers
*/

#include <unistd.h>
#include "./include/rush3.h"

int my_put_nbr(int nb)
{
    long int tmp = nb;
    long int result = 0;

    if (tmp < 0){
        tmp = tmp *( -1);
        my_putchar('-');
    }
    if (tmp == 0 || tmp <= 9){
        my_putchar(tmp + 48);
        return (0);
    }
    if (tmp > 9){
        result = tmp % 10;
        my_put_nbr(tmp / 10);
        my_putchar((result + 48));
    }
}
