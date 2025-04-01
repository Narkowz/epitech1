/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** str cat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    my_strncpy(dest + my_strlen(dest), src, nb);
    if (nb > src)
        return (dest + my_strlen(dest));
    return dest;
}
