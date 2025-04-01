/*
** EPITECH PROJECT, 2024
** char_to_int.c
** File description:
** char_to_int
*/

#include "include/my_radar.h"

float extract_number(char *str, int spaces)
{
    int result = 0;
    int sign = 1;
    int count = 0;
    int i = 2;

    while (str[i] != '\0' && count < spaces) {
        if (str[i] == ' ')
            count++;
        if (count == spaces - 1 && (str[i] >= '0' && str[i] <= '9')) {
            result = result * 10 + (str[i] - '0');
        }
        i++;
    }
    return result * sign;
}
