/*
** EPITECH PROJECT, 2025
** concat.c Ex04
** File description:
** Ex 04 of Day04am of the pool Tech2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

static char *my_revstr(char *str)
{
    int len = strlen(str);
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

void print_reverse(const char *str)
{
    char *new = strdup(str);

    new = my_revstr(new);
    printf("%s\n", new);
    free(new);
}

void print_upper(const char *str)
{
    char *new = strdup(str);

    for (int i = 0; new[i] != '\0'; i++)
        if (new[i] >= 'a' && new[i] <= 'z')
            new[i] = new[i] - 32;
    printf("%s\n", new);
    free(new);
}

void print_42(const char *str)
{
    (void)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*actions[PRINT_COUNT])(const char *str) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

    if (action >= 0 && action < PRINT_COUNT)
        actions[action](str);
}

int main ( void )
{
const char *str = "So long , and thanks for all the fish .";
do_action ( PRINT_NORMAL , str ) ;
do_action ( PRINT_REVERSE , str );
do_action ( PRINT_UPPER , str ) ;
do_action ( PRINT_42 , str) ;
return (0) ;
}