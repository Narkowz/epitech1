/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** strlen
*/

#include "../../include/my_printf.h"
#include <unistd.h>

int my_strlen(char const *str)
{
    int nbr = 0;

    while (str[nbr] != '\0') {
        nbr++;
    }
    return (nbr);
}
