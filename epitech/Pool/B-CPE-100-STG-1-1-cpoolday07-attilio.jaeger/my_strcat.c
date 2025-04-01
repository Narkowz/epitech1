/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** str cat
*/

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}
