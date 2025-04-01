/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** turns
*/

#include "../include/need4stek.h"

void do_turn(char **coo_lidar, char **buf, size_t size)
{
    float middle = atoi(coo_lidar[count_lines(coo_lidar) / 2]);
    int average = atoi(coo_lidar[0]) - atoi(coo_lidar[count_lines(coo_lidar) - 1]);
    float angle;

    if ((average < 0 && middle < 900) || atoi(coo_lidar[0]) < 300) {
        write(1, "CAR_FORWARD:0.1\n", 16);
        getline(buf, &size, stdin);
        write(1, "WHEELS_DIR:-0.4\n", 16);
        getline(buf, &size, stdin);
        while ((average < -200 && average > 200) || middle < 700) {
            write(1, "GET_INFO_LIDAR\n", 15);
            getline(buf, &size, stdin);
            if (strstr(*buf, "Lap Cleared") != NULL || strstr(*buf, "Track Cleared") != NULL)
                return;
            coo_lidar = my_str_to_word_array(*buf, coo_lidar);
            average = atoi(coo_lidar[0]) - atoi(coo_lidar[count_lines(coo_lidar) - 1]);
            middle = atoi(coo_lidar[count_lines(coo_lidar) / 2]);
        }
    } else if ((average > 0 && middle < 900) || atoi(coo_lidar[count_lines(coo_lidar) - 1]) < 300) {
        write(1, "CAR_FORWARD:0.1\n", 16);
        getline(buf, &size, stdin);
        write(1, "WHEELS_DIR:0.4\n", 15);
        getline(buf, &size, stdin);
        while ((average < -200 && average > 200) || middle < 700) {
            write(1, "GET_INFO_LIDAR\n", 15);
            getline(buf, &size, stdin);
            if (strstr(*buf, "Lap Cleared") != NULL || strstr(*buf, "Track Cleared") != NULL)
                return;
            coo_lidar = my_str_to_word_array(*buf, coo_lidar);
            average = atoi(coo_lidar[0]) - atoi(coo_lidar[count_lines(coo_lidar) - 1]);
            middle = atoi(coo_lidar[count_lines(coo_lidar) / 2]);
        }
    }
    write(1, "CAR_FORWARD:0.4\n", 16);
    getline(buf, &size, stdin);
    write(1, "WHEELS_DIR:0\n", 13);
    getline(buf, &size, stdin);
    return;
}

int go_straight(char **coo_lidar, char **buf, size_t size)
{
    int average = atoi(coo_lidar[0]) - atoi(coo_lidar[count_lines(coo_lidar) - 1]);

    if (atoi(coo_lidar[(int) count_lines(coo_lidar) / 2]) < 1300)
        return 1;
    while (atoi(coo_lidar[(int) count_lines(coo_lidar) / 2]) >= 1300) {
        dprintf(2, RED BOLD "tout droit\n" RES);
        write(1, "GET_INFO_LIDAR\n", 15);
        getline(buf, &size, stdin);
        if (strstr(*buf, "Lap Cleared") != NULL || strstr(*buf, "Track Cleared") != NULL)
            return 0;
        coo_lidar = my_str_to_word_array(*buf, coo_lidar);
        write(1, "CAR_FORWARD:0.7\n", 16);
        getline(buf, &size, stdin);
        if (atoi(coo_lidar[0]) < 400 || atoi(coo_lidar[(int) count_lines(coo_lidar) - 1]) < 400)
            return 1;
    }
    return 0;
}

void handling_turn(char **buf, size_t size, char **coo_lidar)
{
    int lap = 0;

    while (strstr(*buf, "Track Cleared") == NULL && lap != 2) {
        write(1, "GET_INFO_LIDAR\n", 15);
        getline(buf, &size, stdin);
        coo_lidar = my_str_to_word_array(*buf, coo_lidar);
        if (go_straight(coo_lidar, buf, size) == 1)
            do_turn(coo_lidar, buf, size);
        if (strstr(*buf, "Lap Cleared") != NULL)
            lap++;
    }
}
