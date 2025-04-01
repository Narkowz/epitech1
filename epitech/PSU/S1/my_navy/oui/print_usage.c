/*
** EPITECH PROJECT, 2024
** print_usage.c
** File description:
** print_usage
*/

#include "include/my.h"
#include "include/my_navy.h"

void print_usage(void)
{
    mini_printf("USAGE\n");
    mini_printf("\t./my_navy [first_player_pid] navy_positions\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("\tfirst_player_pid: only for the 2nd player. pid of the ");
    mini_printf("first player.\n\tnavy_positions: file representing the ");
    mini_printf("positions of the ships.\n");
}
