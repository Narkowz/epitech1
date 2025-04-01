/*
** EPITECH PROJECT, 2024
** cesar
** File description:
** main.c
*/

#include "include/cesar.h"

void capitalize(char *file, char **decrypt, int i, int number)
{
    (*decrypt)[i] = (file[i] - 'A') % 26;
    if ((*decrypt)[i] - number < 0) {
        (*decrypt)[i] += 91;
        (*decrypt)[i] = (*decrypt)[i] - number;
        return;
    }
    (*decrypt)[i] = (*decrypt)[i] - number + 'A';
}

void minimalize(char *file, char **decrypt, int i, int number)
{
    (*decrypt)[i] = (file[i] - 'a') % 26;
    if ((*decrypt)[i] - number < 0) {
        (*decrypt)[i] += 123;
        (*decrypt)[i] = (*decrypt)[i] - number;
        return;
    }
    (*decrypt)[i] = (*decrypt)[i] - number + 'a';
}

int cesar_decrypt(char *file, int number, char **decrypt)
{
    int iscapital = 0;
    int i = 0;

    for (; file[i] != '\0'; i++) {
        if ((file[i] < 'A' || file[i] > 'Z') &&
            (file[i] < 'a' || file[i] > 'z')) {
            (*decrypt)[i] = file[i];
            continue;
        }
        if (file[i] >= 'a' && file[i] <= 'z')
            iscapital = 0;
        else
            iscapital = 1;
        if (iscapital == 1)
            capitalize(file, decrypt, i, number);
        else
            minimalize(file, decrypt, i, number);
    }
    (*decrypt)[i] = '\0';
    return 0;
}

int main(int ac, char **av)
{
    char *file = NULL;
    char *decrypt = NULL;

    if (ac != 4)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'f') {
        file = opening_file(av[2]);
        if (file == NULL)
            return 84;
        decrypt = malloc(sizeof(char *) * (strlen(file) + 1));
        cesar_decrypt(file, atoi(av[3]), &decrypt);
        printf("%s\n", decrypt);
        free(decrypt);
        free(file);
    }
    return 0;
}
