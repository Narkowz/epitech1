/*
** EPITECH PROJECT, 2023
** concat_params.c
** File description:
** concat params
*/

#include <stdlib.h>

void my_putchar_1(char c)
{
    write(1, &c, 1);
}

int my_putstr_1(char *str)
{
    int i = 0;
    char c;

    for (; str[i] != '\0' ; i++) {
        c = str[i];
        my_putchar_1(c);
    }
    return 0;
}

int my_strlen_1(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

static void put(char *str)
{
    my_putchar_1(*str);
    str++;
}

char *my_strcat_1(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    if (dest == 0 || src == 0) {
        return (0);
    }
    while (dest[a] != '\0') {
        a++;
    }
    while (src[b] != '\0') {
        dest[a] = src[b];
        a++;
        my_putstr_1(*src);
            }
    while (*src != '\0') {
        put(&src);
    }
    b++;
    dest[a] = '\0';
    return (dest);
}

char *concat_params(int argc, char **argv)
{
    char *dest;
    int dest_length = 0;
    int a = 0;

    while (a < argc) {
        dest_length = dest_length + my_strlen_1(argv[a]) + 1;
        a++;
    }
    dest = malloc(sizeof(char) * dest_length + 1);
    a = 0;
    while (a < argc) {
        my_strcat_1(my_strcat_1(dest, argv[a]), "\n");
        a++;
    }
    my_strcat_1(dest, "\0");
    return (dest);
}
