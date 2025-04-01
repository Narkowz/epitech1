/*
** EPITECH PROJECT, 2024
** N4S
** File description:
** float to str
*/

#include "../include/need4stek.h"

int int_length(int num)
{
    int length = 0;

    if (num == 0)
        return 1;
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}

char *int_to_string(int num, char **str, int length)
{
    if (num == 0) {
        (*str)[0] = '0';
        (*str)[1] = '\0';
        return *str;
    }
    for (int i = length - 1; i >= 0; i--) {
        (*str)[i] = (num % 10) + '0';
        num /= 10;
    }
    (*str)[length] = '\0';
    return *str;
}

char *my_get_str(float number)
{
    char *result = malloc(sizeof(char) * (int_length((int) number) + 3));
    char *floatter = malloc(sizeof(char) * 2);
    int length = int_length((int) number);

    int_to_string((int) number, &result, length);
    number -= (int) number;
    number *= 10;
    int_to_string((int) number, &floatter, 1);
    result = strcat(result, ".");
    result = strcat(result, floatter);
    free(floatter);
    return result;
}
