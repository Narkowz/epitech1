/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** my_revstr
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

char *my_revstr(char  *str)
{
    int fin;
    int debut;
    char temp;

    fin = my_strlen(str) - 1;
    debut = 0;
    while (debut < fin) {
        temp = str[debut];
        str[debut] = str[fin];
        str[fin] = temp;
        debut = debut + 1;
        fin = fin - 1;
    }
    return (str);
}
