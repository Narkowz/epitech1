/*
** EPITECH PROJECT, 2023
** RUSH-1-1
** File description:
** Fonction rush 1-1;
*/

static int my_putstr(char *str)
{
    int i = 0;
    char c;

    for (; str[i] != '\0' ; i++) {
        c = str[i];
        my_putchar(c);
    }
    return 0;
}

void side_floor_1(int *pos_x, int *pos_y, int x, int y)
{
    if (*pos_y == 0 || *pos_y == y){
        if (*pos_x == 0 || *pos_x == x){
            my_putchar('o');
        }
        if (*pos_x > 0 && *pos_x < x){
            my_putchar('-');
        }
    }
}

void side_1(int *pos_x, int *pos_y, int x, int y)
{
    if (*pos_y > 0 && *pos_y < y){
        if (*pos_x == 0 || *pos_x == x){
            my_putchar('|');
        }
        if (*pos_x > 0 && *pos_x < x){
            my_putchar(' ');
        }
    }
}

void rush(int x, int y)
{
    int pos_x = 0;
    int pos_y = 0;

    --x;
    --y;
    if (y <= -1 || x <= -1 || x > 2147483646 || y > 2147483646) {
        my_putstr("Invalid size\n");
        return;
    }
    while (pos_y <= y){
        while (pos_x <= x){
            side_floor_1(&pos_x, &pos_y, x, y);
            side_1(&pos_x, &pos_y, x, y);
            ++pos_x;
        }
        my_putchar('\n');
        pos_x = 0;
        ++pos_y;
    }
}
