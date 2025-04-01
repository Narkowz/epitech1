/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** turns
*/

#include "../include/need4stek.h"

void reg_angle(float *angle, int coo_bigger)
{
    *angle = ((coo_bigger / 17.0) - 1) / 3.4;
    if (*angle > 3.0)
        *angle = 6.00;
}

void do_turn(float angle, char *wheel, char **string, int coo_bigger, char **coo_lidar, char *buf, size_t size)
{
    if (coo_bigger < 8 || atoi(coo_lidar[0]) < 375) {
        write(1, "CAR_FORWARD:0.2\n", 16);
        getline(&buf, &size, stdin);
        angle = ((17 - coo_bigger) / 17.0) / 3.4;
        if (angle > 3.0)
            angle = 6.00;
        add_word_to_string(wheel, my_get_str(angle), string, ":");
        dprintf(2, RED BOLD "turn gauche %s\n" RES, *string);
        dprintf(1, "%s\n", *string);
        getline(&buf, &size, stdin);
        return;
    } else if (coo_bigger > 28 || atoi(coo_lidar[count_lines(coo_lidar) - 1]) < 200) {
        write(1, "CAR_FORWARD:0.2\n", 16);
        getline(&buf, &size, stdin);
        reg_angle(&angle, coo_bigger);
        add_word_to_string(wheel, my_get_str(angle), string, ":-");
        dprintf(2, RED BOLD "turn droite %s\n" RES, *string);
        dprintf(1, "%s\n", *string);
        getline(&buf, &size, stdin);
        return;
    } else {
        write(1, "WHEELS_DIR:0\n", 13);
        getline(&buf, &size, stdin);
        write(1, "CAR_FORWARD:0.4\n", 16);
        getline(&buf, &size, stdin);
        return;
    }
}

int accurate_turn(char **coo_lidar, char *buf, size_t size)
{
    if (atoi(coo_lidar[0]) < 300) {
        write(1, "CAR_FORWARD:0.2\n", 16);
        getline(&buf, &size, stdin);
        write(1, "WHEELS_DIR:-0.3\n", 16);
        getline(&buf, &size, stdin);
        dprintf(2, GREEN BOLD "droite\n" RES);
        while (atoi(coo_lidar[0]) < 200) {
            write(1, "GET_INFO_LIDAR\n", 15);
            getline(&buf, &size, stdin);
            coo_lidar = my_str_to_word_array(buf, coo_lidar);
        }
        return 1;
    }
    if (atoi(coo_lidar[count_lines(coo_lidar) - 1]) < 280) {
        write(1, "CAR_FORWARD:0.2\n", 16);
        getline(&buf, &size, stdin);
        write(1, "WHEELS_DIR:0.3\n", 15);
        getline(&buf, &size, stdin);
        while (atoi(coo_lidar[0]) < 200) {
            write(1, "GET_INFO_LIDAR\n", 15);
            getline(&buf, &size, stdin);
            coo_lidar = my_str_to_word_array(buf, coo_lidar);
        }
        dprintf(2, GREEN BOLD "gauche\n" RES);
        return 1;
    }
    return 0;
}

void handling_turn(char *buf, size_t size, char **coo_lidar)
{
    int coo_bigger = 0;
    float angle = 0;
    char *wheel = malloc(sizeof(char) * strlen("WHEEL_DIR\0"));
    char *string = NULL;

    wheel = my_strdup("WHEELS_DIR\0");
    for (int bigger; strstr(buf, "Track Cleared") == NULL;) {
        write(1, "GET_INFO_LIDAR\n", 15);
        getline(&buf, &size, stdin);
        coo_lidar = my_str_to_word_array(buf, coo_lidar);
        if (accurate_turn(coo_lidar, buf, size) == 1) {
            write(1, "WHEELS_DIR:0\n", 13);
            getline(&buf, &size, stdin);
        }
        for (int i = 0; coo_lidar[i] != NULL; i++)
            write(2, coo_lidar[i], strlen(coo_lidar[i]));
        write(2, "\n\n", 2);
        coo_bigger = find_bigger(coo_lidar, bigger);
        do_turn(angle, wheel, &string, coo_bigger, coo_lidar, buf, size);
        // getline(&buf, &size, stdin);
    }
}
