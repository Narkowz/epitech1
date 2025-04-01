/*
** EPITECH PROJECT, 2024
** print_usage.c
** File description:
** print_usage
*/

#include "../include/robotfactory.h"

void print_usage(void)
{
    my_printf("USAGE\n./asm file_name[.s]\n");
    my_printf("DESCRIPTION\nfile_name file in assembly language to be ");
    my_printf("converted into file_name.cor, an executable in the Virtual ");
    my_printf("Machine.\n");
}
