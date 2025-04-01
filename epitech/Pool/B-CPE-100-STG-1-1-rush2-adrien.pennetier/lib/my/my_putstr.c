/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr
*/

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
