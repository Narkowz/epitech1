/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** str cat
*/

char *my_strcat(char *dst, char const *src)
{
    my_strcpy(dst + my_strlen(dst), src);
    return dst;
}
