/*
** EPITECH PROJECT, 2024
** start_game.c
** File description:
** start_game
*/

#include "include/my.h"
#include "include/my_navy.h"

extern global_t global;

char **read_file(char *path, char **map)
{
    int fd;
    char *buf;
    int state;
    int i;

    fd = open(path, O_RDONLY);
    buf = malloc(sizeof(char) * (31 + 1));
    for (int k = 0; k <= 32; k++)
        buf[k] = '\0';
    state = read(fd, buf, 32);
    close(fd);
    map = customize_map(map, buf);
    return map;
}

int start_game2(char *path, struct sigaction *action, second_t *navy,
    pid_t pid_player1)
{
    navy->my_map = read_file(path, navy->my_map);
    mini_printf("\nmy navy:\n");
    for (int i = 0; i < 10; i++)
        mini_printf("%s\n", navy->my_map[i]);
    mini_printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        mini_printf("%s\n", navy->enemy_map[k]);
    action->sa_handler = player_turn_handler;
    sigaction(SIGUSR1, action, NULL);
    sigaction(SIGUSR2, action, NULL);
    while (!global.stop_game) {
        mini_printf("\nwaiting for enemy's attack...\n");
        while (!global.player_turn)
            usleep(5000);
        mini_printf("\nresult: \n\n");
        send_message(pid_player1);
        notify_opponent(pid_player1, SIGUSR2);
        global.player_turn = 0;
        mini_printf("\nresult: \n");
    }
}

int start_game1(char *path, struct sigaction *action, first_t *navy)
{
    navy->my_map = read_file(path, navy->my_map);
    mini_printf("my navy:\n");
    for (int i = 0; i < 10; i++)
        mini_printf("%s\n", navy->my_map[i]);
    mini_printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        mini_printf("%s\n", navy->enemy_map[k]);
    action->sa_handler = player_turn_handler;
    sigaction(SIGUSR1, action, NULL);
    sigaction(SIGUSR2, action, NULL);
    while (!global.stop_game) {
        while (global.player_turn)
            usleep(5000);
        printf("\n");
        send_message(global.opponent_pid);
        notify_opponent(global.opponent_pid, SIGUSR1);
        mini_printf("\nresult: \n");
        mini_printf("\nwaiting for enemy's attack...\n");
        global.player_turn = 1;
    }
}
