/*
** EPITECH PROJECT, 2023
** print_usage.c
** File description:
** print_usage
*/

#include "include/my_radar.h"
#include <stdio.h>

void print_usage(void)
{
    mini_printf("Air traffic simulation panel\n\nUSAGE\n ./my_radar [OPTIONS]");
    mini_printf(" path_to_script\n path_to_script\tThe path to the script file.");
    mini_printf("\n\nOPTIONS\n -h\t\t\tprint the usage and quit.\n\n");
    mini_printf("USER INTERACTIONS\n 'L' key\tenable/disable hitboxes and ");
    mini_printf("areas.\n 'S' key\tenable/disable sprites.\n");
}
