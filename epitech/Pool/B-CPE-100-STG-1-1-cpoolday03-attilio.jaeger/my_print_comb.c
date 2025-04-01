/*
** EPITECH PROJECT, 2023
** my_print_comb.c
** File description:
** Display all three digits numbers
*/

int comma(int a, int b, int c)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
    if (a != 55) {
        my_putchar(44);
        my_putchar(32);
    }
    return (a);
}

int for1(int a, int b)
{
    for (int c = b + 1; c <= 57; c++) {
        comma(a, b, c);
    }
}

int my_print_comb(void)
{
    for (int a = 48; a <= 55; a++){
        for (int b = a + 1; b <= 56; b++){
            for1(a, b);
        }
    }
}
