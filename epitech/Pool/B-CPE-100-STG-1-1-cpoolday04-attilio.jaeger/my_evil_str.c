/*
** EPITECH PROJECT, 2023
** my_evil_str.c
** File description:
** ruojnob
*/

int my_strlen_bis(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *revstr(char *str)
{
    int len = my_strlen_bis(str);
    int j = len;
    int i = 0;
    char tmp;

    for (; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[j - 1];
        str[j - 1] = tmp;
        j--;
    }
    return (str);
}

char *my_evil_str(char *str)
{
    str = revstr(strdup(str));
    return str;
}
