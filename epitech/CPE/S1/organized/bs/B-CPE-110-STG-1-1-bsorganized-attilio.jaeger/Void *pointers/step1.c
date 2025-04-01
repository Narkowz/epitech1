/*
** EPITECH PROJECT, 2023
** step1.c
** File description:
** step1
*/

#include <stdio.h>
#include <string.h>
#include "organized.h"

void print_typed_value(void *data, type_t type)
{
    if (type == INTEGER) {
        printf("%d\n", *((int *)data));
    } else if (type == CHAR) {
        printf("%c\n", *((char *)data));
    } else if (type == STRING) {
        printf("%s\n", (char *)data);
    } else if (type == PLAYER) {
        player_t *player = (player_t *)data;
        printf("%s: lvl.%d\n", player->player, player->lvl);
    }
}

int main(int argc, char **argv)
{
    type_t type;
    int nb = 3;
    char c = 'k';
    char *str = strdup("Jonathan");
    player_t player = {strdup("Nau"), 98};

    print_typed_value(&nb, INTEGER);
    print_typed_value(&c, CHAR);
    print_typed_value(str, STRING);
    print_typed_value(&player, PLAYER);
    return 0;
}
