/*
** EPITECH PROJECT, 2024
** cesar
** File description:
** main.c
*/

#include "include/cesar.h"
#include <sys/stat.h>

void capitalize(char *file, char **crypt, int i, int number)
{
    (*crypt)[i] = (file[i] - 'A') % 26;
    if ((*crypt)[i] + number > 25) {
        (*crypt)[i] += 39;
        (*crypt)[i] = (*crypt)[i] + number;
        return;
    }
    (*crypt)[i] = (*crypt)[i] + number + 'A';
}

void minimalize(char *file, char **crypt, int i, int number)
{
    (*crypt)[i] = (file[i] - 'a') % 26;
    if ((*crypt)[i] + number > 25) {
        (*crypt)[i] += 71;
        (*crypt)[i] = (*crypt)[i] + number;
        return;
    }
    (*crypt)[i] = (*crypt)[i] + number + 'a';
}

int cesar_crypt(char *file, int number, char **crypt)
{
    int iscapital = 0;
    int i = 0;

    for (; file[i] != '\0'; i++) {
        if ((file[i] < 'A' || file[i] > 'Z') &&
            (file[i] < 'a' || file[i] > 'z')) {
            (*crypt)[i] = file[i];
            continue;
        }
        if (file[i] >= 'a' && file[i] <= 'z')
            iscapital = 0;
        else
            iscapital = 1;
        if (iscapital == 1)
            capitalize(file, crypt, i, number);
        else
            minimalize(file, crypt, i, number);
    }
    (*crypt)[i] = '\0';
    return 0;
}

int write_file(char *crypt)
{
    size_t size = 0;
    FILE *file;

    file = fopen("crypt", "w+");
    fwrite(crypt, sizeof(crypt), strlen(crypt), file);
    fclose(file);
    chmod("crypt", 00444);
}

int main(int ac, char **av)
{
    char *file = NULL;
    char *crypt = NULL;

    if (ac != 4 || av[2] == NULL || av[2][0] == '\0')
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'f') {
        file = opening_file(av[2]);
        if (file == NULL)
            return 84;
        crypt = malloc(sizeof(char *) * (strlen(file) + 1));
        cesar_crypt(file, atoi(av[3]), &crypt);
        free(file);
    } else if (av[1][0] == '-' && av[1][1] == 's') {
        crypt = malloc(sizeof(char *) * (strlen(av[2]) + 1));
        cesar_crypt(av[2], atoi(av[3]), &crypt);
    } else
        return 84;
    write_file(crypt);
    free(crypt);
    return 0;
}
