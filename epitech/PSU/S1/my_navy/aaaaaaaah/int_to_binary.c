/*
** EPITECH PROJECT, 2024
** int_to_binary.c
** File description:
** int_to_binary
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/my_navy.h"

int *int_to_binarys(char *msg)
{
    int *binary = malloc(sizeof(int) * 9);
    int i = 0;
    int int_arg;
    printf("test\n");

    for (int k = 0; msg[k] != '\0'; k++) {
        int_arg = (int)msg[k];
        while (int_arg > 0) {
            binary[i] = int_arg % 2;
            int_arg /= 2;
            i++;
        }
        while (i % 4 != 0) {
            binary[i] = 0;
            i++;
        }
    }
    binary[i] = -1;
    return binary;
}

void int_to_binary(char *msg)
{
    int *res = int_to_binarys(msg);
    int i = 0;

    for (; res[i] != -1; i++);
    for (int k = i - 1; k >= 0; k--)
        printf("%d", res[k]);
    printf("\n");
}

char binary_to_char(int *arg)
{
    char res;
    int i = 0;
    int k = 0;
    int result = 0;
    int bit_position = 1;

    for (; arg[k] != -1; k++);
    for (i = k - 1; i >= 0; i--) {
        result += arg[i] * bit_position;
        bit_position *= 2;
    }
    res = (char)result + 64;
    return res;
}

int main(void)
{
    int_to_binary("B1");
    return 0;
}
