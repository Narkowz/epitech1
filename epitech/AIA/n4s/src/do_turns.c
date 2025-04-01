/*
** EPITECH PROJECT, 2024
** Need4Steck
** File description:
** do turns
*/

#include "../include/need4stek.h"

void do_turn_2(all_t *all, size_t size)
{
    while ((all->average < -200 && all->average > 200) || all->middle < 700) {
        write_ev(all, size, "GET_INFO_LIDAR\n");
        all->coo_lidar = my_str_to_word_array(all->buf, all->coo_lidar);
        all->average = atoi(all->coo_lidar[0]) -
            atoi(all->coo_lidar[count_lines(all->coo_lidar) - 1]);
        all->middle = atoi(all->coo_lidar[count_lines(all->coo_lidar) / 2]);
    }
    return;
}

void do_turn_3(all_t *all, size_t size)
{
    write_ev(all, size, "GET_INFO_LIDAR\n");
    all->coo_lidar = my_str_to_word_array(all->buf, all->coo_lidar);
    all->average = atoi(all->coo_lidar[0]) -
        atoi(all->coo_lidar[count_lines(all->coo_lidar) - 1]);
    all->middle = atoi(all->coo_lidar[count_lines(all->coo_lidar) / 2]);
    return;
}

void do_turn_big(all_t *all, size_t size)
{
    if ((all->average < 0 && all->middle < 900) ||
        atoi(all->coo_lidar[0]) < 300) {
        write_ev(all, size, "CAR_FORWARD:0.1\n");
        write_ev(all, size, "WHEELS_DIR:-0.4\n");
        while ((all->average < -200 && all->average > 200) ||
            all->middle < 700)
            do_turn_3(all, size);
    } else if ((all->average > 0 && all->middle < 900) ||
        atoi(all->coo_lidar[count_lines(all->coo_lidar) - 1]) < 300) {
        write_ev(all, size, "CAR_FORWARD:0.1\n");
        write_ev(all, size, "WHEELS_DIR:0.4\n");
        do_turn_2(all, size);
    }
    return;
}

void do_turn(all_t *all, size_t size)
{
    all->middle = atoi(all->coo_lidar[count_lines(all->coo_lidar) / 2]);
    all->average = atoi(all->coo_lidar[0]) -
        atoi(all->coo_lidar[count_lines(all->coo_lidar) - 1]);
    do_turn_big(all, size);
    write_ev(all, size, "CAR_FORWARD:0.4\n");
    write_ev(all, size, "WHEELS_DIR:0\n");
    return;
}
