/*
** EPITECH PROJECT, 2023
** my_print_comb2.c
** File description:
** 00 00
*/

int print_comb(int a, int b)
{
    my_putchar(a / 10 + 48);
    my_putchar(a % 10 + 48);
    my_putchar(' ');
    my_putchar(b / 10 + 48);
    my_putchar(b % 10 + 48);
    if (a != 98 || b != 99){
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb2(void)
{
    for (int a = 0; a <= 98; a++){
        for (int b = a + 1; b <= 99; b++){
            print_comb(a, b);
        }
    }
}
