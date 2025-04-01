/*
** EPITECH PROJECT, 2024
** secured
** File description:
** blabla main secured
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "include/secured.h"

int hash(char *key, int len)
{
    int hashValue = 1;
    const int consta = 31;
    int j = 0;

    for (int i = len; i >= 0; i--) {
        j = key[i] - '0';
        hashValue = ((hashValue * (consta * j ^ 5)) * j ^ 2);
    }
    if (hashValue < 0)
        hashValue = hashValue * -1;
    hashValue = hashValue % 1000000000;
    return hashValue;
}

// int main(int ac, char **av)
// {
//     int len = 0;
//     char *key;
//     int hashedValue = 0;

//     if (ac != 2)
//         return 84;
//     len = my_strlen(av[1]) - 1;
//     key = malloc(sizeof(char) * len);
//     key = av[1];
//     hashedValue = hash(key, len);
//     printf("Hashed Value: %d\n", hashedValue);
//     return 0;
// }
