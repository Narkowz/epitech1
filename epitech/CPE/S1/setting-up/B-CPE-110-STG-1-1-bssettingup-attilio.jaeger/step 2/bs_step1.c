/*
** EPITECH PROJECT, 2023
** bs_step1.c
** File description:
** bs_step1
*/

#include <stdio.h>
#include <stdlib.h>

void array_1d_print_chars(char const *arr)
{
    int i = 0;

    while (arr[i]!= '\0') {
        printf("%c", arr[i]);
        i++;
        printf("\n");
    }
}

void main(void)
{
    char *arr = malloc(sizeof(char) * 27);

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'd';
    arr[4] = 'e';
    arr[5] = 'f';
    arr[6] = 'g';
    arr[7] = 'h';
    arr[8] = 'i';
    arr[9] = 'j';
    arr[10] = 'k';
    arr[11] = 'l';
    arr[12] = 'm';
    arr[13] = 'n';
    arr[14] = 'o';
    arr[15] = 'p';
    arr[16] = 'q';
    arr[17] = 'r';
    arr[18] = 's';
    arr[19] = 't';
    arr[20] = 'u';
    arr[21] = 'v';
    arr[22] = 'w';
    arr[23] = 'x';
    arr[24] = 'y';
    arr[25] = 'z';
    arr[26] = '\0';

    array_1d_print_chars(arr);
    free(arr);
}