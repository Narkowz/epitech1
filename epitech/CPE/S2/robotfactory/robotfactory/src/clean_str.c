/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-lois.hattenberger
** File description:
** clean_str
*/

#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int rm_beg_space(char *str)
{
    int i = 0;

    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    return i;
}

static int space_in(char *str, int j)
{
    if (str[j] == ' ' && str[j + 1] == ' ')
        return 0;
    if (str[j] == ' ' && str[j + 1] == '\0')
        return 0;
    my_putchar(str[j]);
    return 0;
}

static int clean_str(char *str)
{
    int i = rm_beg_space(str);

    for (i; str[i] != '\0'; i++) {
        if (str[i] != '\t') {
            space_in(str, i);
        }
    }
    write(1, "\n", 1);
    return 0;
}
