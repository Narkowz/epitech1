/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_isalpha
*/

int my_isalpha(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return (0);
    return (1);
}
