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
    struct stat st;
    int fd = open(path, O_RDONLY);
    char *buf;
    int state;
    int i;

    stat(path, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    for (int k = 0; k <= st.st_size; k++)
        buf[k] = '\0';
    state = read(fd, buf, st.st_size);
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
        while (global.player_turn) {
            usleep(5000);
        }
        mini_printf("Joueur 2 : C'est mon tour\n");
        send_message(pid_player1);
        global.player_turn = 1;
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
    mini_printf("Opponent's PID: %d\n", global.opponent_pid);
    sigaction(SIGUSR1, action, NULL);
    sigaction(SIGUSR2, action, NULL);
    while (!global.stop_game) {
        while (!global.player_turn)
            usleep(5000);
        mini_printf("Joueur 1 : C'est mon tour\n");
        send_message(global.opponent_pid);
        mini_printf("Sending signal to Player 2...\n");
        notify_opponent(global.opponent_pid, SIGUSR1);
        global.player_turn = 0;
    }
}
