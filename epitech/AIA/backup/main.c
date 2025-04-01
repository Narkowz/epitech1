/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** main
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/need4stek.h"

int count_lines(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i++);
    return i;
}

void handling_turn(char *buf, size_t size, char **coo_lidar)
{
    for (; strstr(buf, "Track Cleared") == NULL;) {
        write(1, "GET_INFO_LIDAR\n", 15);
        getline(&buf, &size, stdin);
        // dprintf(2, "'%s'\n", buf);
        coo_lidar = my_str_to_word_array(buf, coo_lidar);
        // dprintf(2, "%d\n", my_getnbr(coo_lidar[3]));
        // dprintf(2, "34 : %d, %s\n", my_getnbr(coo_lidar[count_lines(coo_lidar) - 2]), coo_lidar[count_lines(coo_lidar) - 2]);
        if (strstr(coo_lidar[count_lines(coo_lidar) - 1], "No further info") != NULL && atoi(coo_lidar[3]) <= 350) {
            while (atoi(coo_lidar[3]) <= 300) { //capte à gauche, tourne à droite
                write(1, "CAR_FORWARD:0.25\n", 17);
                getline(&buf, &size, stdin);
                write(1, "WHEELS_DIR:-0.5\n", 16);
                getline(&buf, &size, stdin);
                write(1, "GET_INFO_LIDAR\n", 15);
                getline(&buf, &size, stdin);
                coo_lidar = my_str_to_word_array(buf, coo_lidar);
            }
            write(1, "WHEELS_DIR:0\n", 13);
            getline(&buf, &size, stdin);
        }
        if (strstr(coo_lidar[count_lines(coo_lidar) - 1], "No further info") != NULL && atoi(coo_lidar[count_lines(coo_lidar) - 2]) <= 350) {
            while (atoi(coo_lidar[count_lines(coo_lidar) - 2]) <= 300) { //capte à droite tourne à gauche
                write(1, "CAR_FORWARD:0.25\n", 17);
                getline(&buf, &size, stdin);
                write(1, "WHEELS_DIR:0.5\n", 15);
                getline(&buf, &size, stdin);
                write(1, "GET_INFO_LIDAR\n", 15);
                getline(&buf, &size, stdin);
                coo_lidar = my_str_to_word_array(buf, coo_lidar);
            }
            write(1, "WHEELS_DIR:0\n", 13);
            getline(&buf, &size, stdin);
        }
        write(1, "CAR_FORWARD:0.4\n", 16);
        getline(&buf, &size, stdin);
        // write(1, "WHEELS_DIR:0\n", 13);
        // getline(&buf, &size, stdin);
    }
}

int main(void)
{
    char *buf = NULL;
    size_t size = 0;
    char **coo_lidar = NULL;

    write(1, "START_SIMULATION\n", 17);
    getline(&buf, &size, stdin);
    // dprintf(2, "'%s'\n", buf);
    sleep(1);
    write(1, "CAR_FORWARD:0.3\n", 16);
    getline(&buf, &size, stdin);
    // dprintf(2, "'%s'\n", buf);
    sleep(1);
    handling_turn(buf, size, coo_lidar);
    write(1, "STOP_SIMULATION\n", 16);
    getline(&buf, &size, stdin);
    // dprintf(2, "'%s'\n", buf);
    return 0;
}
