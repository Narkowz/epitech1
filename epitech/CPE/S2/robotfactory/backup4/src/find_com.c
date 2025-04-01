/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-lois.hattenberger
** File description:
** find_com
*/

#include "../include/robotfactory.h"

int find_com(char *str, int j)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '#') {
            j++;
            return j;
        }
    return j;
}
