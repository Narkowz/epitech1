/*
** EPITECH PROJECT, 2024
** initialize_map.c
** File description:
** initialize_map
*/

#include "include/my.h"
#include "include/my_navy.h"

char **init_map(char **map)
{
    int i = 0;

    map = malloc(sizeof(char *) * 10);
    for (; i < 10; i++)
        map[i] = malloc(sizeof(char) * 19);
    my_strcpy(map[0], " |A B C D E F G H");
    my_strcpy(map[1], "-+---------------");
    my_strcpy(map[2], "1|. . . . . . . .");
    my_strcpy(map[3], "2|. . . . . . . .");
    my_strcpy(map[4], "3|. . . . . . . .");
    my_strcpy(map[5], "4|. . . . . . . .");
    my_strcpy(map[6], "5|. . . . . . . .");
    my_strcpy(map[7], "6|. . . . . . . .");
    my_strcpy(map[8], "7|. . . . . . . .");
    my_strcpy(map[9], "8|. . . . . . . .");
    return map;
}

char **intermediate_for(char **map, char *path, int i)
{
    int row = path[i + 1] - 47;
    int col = (path[i] - 65) * 2 + 2;

    for (; row <= path[i + 4] - 47; row++) {
        map[row][(path[i] - 65) * 2 + 2] = path[i - 2];
        for (; col <= (path[i + 3] - 65) * 2 + 2; col += 2)
            map[row][col] = path[i - 2];
    }
    return map;
}

char **customize_map(char **map, char *path)
{
    int i = 2;

    for (; i < my_strlen(path); i += 8)
        if (path[i] >= 'A' && path[i] <= 'Z')
            map = intermediate_for(map, path, i);
    return map;
}
