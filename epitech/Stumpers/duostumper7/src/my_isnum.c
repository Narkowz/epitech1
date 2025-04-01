/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_isnum
*/

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}
