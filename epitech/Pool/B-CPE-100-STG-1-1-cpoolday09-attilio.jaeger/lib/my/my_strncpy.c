/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** copy string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
