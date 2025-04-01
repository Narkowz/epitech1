/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** turns
*/

#include "../include/need4stek.h"

int write_ev(all_t *all, size_t size, char *str)
{
    int len = strlen(str);

    write(1, str, len);
    getline(&all->buf, &size, stdin);
    if (strstr(all->buf, "Track Cleared") != NULL)
        end_simu(all, size);
    if (strstr(all->buf, "Lap Cleared") != NULL)
        all->lap++;
    return 0;
}

int go_straight(all_t *all, size_t size)
{
    all->average = atoi(all->coo_lidar[0]) -
        atoi(all->coo_lidar[count_lines(all->coo_lidar) - 1]);
    if (atoi(all->coo_lidar[(int) count_lines(all->coo_lidar) / 2]) < 1300)
        return 1;
    while (atoi(all->coo_lidar[(int) count_lines(all->coo_lidar) / 2])
        >= 1300) {
        dprintf(2, RED BOLD "tout droit\n" RES);
        write_ev(all, size, "GET_INFO_LIDAR\n");
        all->coo_lidar = my_str_to_word_array(all->buf, all->coo_lidar);
        write_ev(all, size, "CAR_FORWARD:0.7\n");
        if (atoi(all->coo_lidar[0]) < 400 ||
            atoi(all->coo_lidar[(int) count_lines(all->coo_lidar) - 1]) < 400)
            return 1;
    }
    return 0;
}

void handling_turn(size_t size, all_t *all)
{
    int lap = 0;

    while (strstr(all->buf, "Track Cleared") == NULL && all->lap != 2) {
        write_ev(all, size, "GET_INFO_LIDAR\n");
        all->coo_lidar = my_str_to_word_array(all->buf, all->coo_lidar);
        if (go_straight(all, size) == 1)
            do_turn(all, size);
    }
    return;
}
