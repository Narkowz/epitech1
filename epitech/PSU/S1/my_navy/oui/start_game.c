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
    printf("\nmy navy:\n");
    for (int i = 0; i < 10; i++)
        printf("%s\n", navy->my_map[i]);
    printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        printf("%s\n", navy->enemy_map[k]);
    action->sa_handler = player_turn_handler;
    sigaction(SIGUSR1, action, NULL);
    sigaction(SIGUSR2, action, NULL);
    while (!global.stop_game) {
        while (global.player_turn != 1)
            usleep(5000);
        send_message(pid_player1);
        // printf("ici est global %d\n", global.player_turn);
        global.player_turn = 0;
        printf("\nresult: \n\n");
        printf("waiting for enemy's attack...\n");
    }
}

int start_game1(char *path, struct sigaction *action, first_t *navy)
{
    navy->my_map = read_file(path, navy->my_map);
    printf("my navy:\n");
    for (int i = 0; i < 10; i++)
        printf("%s\n", navy->my_map[i]);
    printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        printf("%s\n", navy->enemy_map[k]);
    action->sa_handler = player_turn_handler;
    sigaction(SIGUSR1, action, NULL);
    sigaction(SIGUSR2, action, NULL);
    while (!global.stop_game) {
        while (global.player_turn)
            usleep(5000);
        // printf("\n");
        send_message(global.opponent_pid);
        // printf("aaaaaaah\n");
        if (global.first->last_shoot == 1)
            printf("\nresult: %s:hit\n", global.message);
        printf("\nwaiting for enemy's attack...\n");
        global.player_turn = 1;
        // printf("glob %d\n", global.player_turn);
    }
}
