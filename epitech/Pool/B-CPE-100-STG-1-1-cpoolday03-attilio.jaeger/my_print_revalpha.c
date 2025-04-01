/*
** EPITECH PROJECT, 2023
** my_print_revalpha.c
** File description:
** Print alphabet in reverse
*/
int my_print_revalpha(void)
{
    int i;

    for (i = 122; i >= 97; i--){
        my_putchar(i);
    }
}
