/*
** EPITECH PROJECT, 2023
** RUSH-1-5
** File description:
** Fonction rush 1-5;
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

void x_equal_1_5(int *pos_x, int x)
{
    while (*pos_x <= x){
        my_putchar('B');
        (*pos_x)++;
    }
    my_putchar('\n');
}

void y_equal_1_5(int *pos_y, int y)
{
    while (*pos_y <= y){
        my_putchar('B');
        (*pos_y)++;
    }
    my_putchar('\n');
}

void side_floor_5(int *pos_x, int *pos_y, int x, int y)
{
    if (*pos_y == 0 || *pos_y == y){
        if ((*pos_x == 0 && *pos_y == 0) || (*pos_x == x && *pos_y == y)){
            my_putchar('A');
        }
        if ((*pos_x == x && *pos_y == 0) || (*pos_x == 0 && *pos_y == y)){
            my_putchar('C');
        }
        if (*pos_x > 0 && *pos_x < x){
            my_putchar('B');
        }
    }
}

static void side_5(int *pos_x, int *pos_y, int x, int y)
{
    if (*pos_y > 0 && *pos_y < y){
        if (*pos_x == 0 || *pos_x == x){
            my_putchar('B');
        }
        if (*pos_x > 0 && *pos_x < x){
            my_putchar(' ');
        }
    }
}

void four_corner_5(int *pos_x, int *pos_y, int x, int y)
{
    while (*pos_y <= y){
        while (*pos_x <= x){
            side_floor_5(pos_x, pos_y, x, y);
            side_5(pos_x, pos_y, x, y);
            (*pos_x)++;
        }
        my_putchar('\n');
        *pos_x = 0;
        (*pos_y)++;
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
    if (y == 0){
        y_equal_1_5(&pos_y, y);
    } else if (x == 0){
        x_equal_1_5(&pos_x, x);
    } else {
        four_corner_5(&pos_x, &pos_y, x, y);
    }
}
