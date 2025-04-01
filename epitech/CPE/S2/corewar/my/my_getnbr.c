/*
** EPITECH PROJECT, 2023
** my strncmp
** File description:
** idk
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "./my.h"

int main(void)
{
    char *str = "42a43";
    int i = 0;
    int nb = 0;
    int neg = 1;

    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            neg = neg * -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++)
        nb = nb * 10 + (str[i] -48);
    my_printf("%d\n", nb * neg);
    return (nb * neg);
}
