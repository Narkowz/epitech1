/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int rc;

    rc = 0;
    while (str[rc] != '\0') {
        rc = rc + 1;
    }
    return (rc);
}
