/*
** EPITECH PROJECT, 2024
** my_navy.h
** File description:
** my_navy
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_

typedef struct first_s {
    char **my_map;
    char **enemy_map;
    int is_running;
} first_t;

typedef struct second_s {
    char **my_map;
    char **enemy_map;
    int is_runnig;
} second_t;

typedef struct global_s {
    int is_running;
    int player_turn;
    int stop_game;
    pid_t opponent_pid;
} global_t;

void print_usage(void);
int testing_file(char *path);
void int_to_binary(char *msg);
int binary_to_int(char *arg);
char **init_map(char **map);
char **read_file(char *path, char **map);
char **customize_map(char **map, char *path);
char **my_str_to_word_array(char *path);
int test_file(char *path);
void player_turn_handler(int signum);
int start_game1(char *path, struct sigaction *action, first_t *navy);
int send_message(pid_t opponent_pid);
void notify_opponent(pid_t opponent_pid, int signal);
int start_game2(char *path, struct sigaction *action, second_t *navy,
    pid_t pid_player1);

#endif /* !MY_NAVY_H_ */
