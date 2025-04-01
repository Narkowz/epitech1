/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "../my/my.h"

int print_h(void)
{
    my_printf("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] [-a load");
    my_printf("_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle dumps ");
    my_printf("the memory after the nbr_cycle execution (if the round isn't");
    my_printf("\nalready over) with the following format: 32 bytes/line in ");
    my_printf("hexadecimal (A0BCDEFE1DD3...)\n-n prog_number sets the next ");
    my_printf("program's number.By default, the first free number in the\np");
    my_printf("arameter order\n-a load_address sets the next program's load");
    my_printf("ing address. When no address is specified,\noptimize the add");
    my_printf("resses so that the processes are as far away from each other");
    my_printf(" as\npossible. The addresses are MEM_SIZE modulo.\n");
    return 0;
}
