/*
** EPITECH PROJECT, 2023
** count_island.c
** File description:
** count island of a map
*/



int count_island(char **world)
{
    int x = 0;
    int y = 0;
    int a = 1;
    int count = 0;
    char **str[14][67];

    my_strcpy(&str, &world);
    printf("%s", str);
    for (; world[y] != '\0'; y++) {
        x = 0;
        a++;
        for (; world[y][x] != '\0'; x++) {
            if (world[y][x] == 'X' && str[a][x] == 'X') {
                count++;
            }
        }
    }
    printf("%d", count);
    return (count);
}
