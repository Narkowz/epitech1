/*
** EPITECH PROJECT, 2023
** display_usage.c
** File description:
** display_usage
*/

#include "include/my_sokoban.h"

void display_usage(void)
{
    mini_printf("USAGE\n");
    mini_printf("\t./my_sokoban map\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("\tmap\tfile representing the warehouse map, containing '#'");
    mini_printf(" for walls,\n\t\t'P' for the player, 'X' for boxes and 'O'");
    mini_printf(" for storage locations.\n");
}
