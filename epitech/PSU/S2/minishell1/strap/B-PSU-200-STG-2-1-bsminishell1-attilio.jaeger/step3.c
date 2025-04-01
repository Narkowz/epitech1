/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av, char **env)
{
    char *strtoken;

    strtoken = strtok(av[1], " ");
    while (strtoken != NULL) {
        printf("%s\n", strtoken);
        strtoken = strtok(NULL, " ");
    }
    execve("/bin/ls", NULL, NULL);
    return 0;
}
