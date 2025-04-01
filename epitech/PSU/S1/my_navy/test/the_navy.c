/*
** EPITECH PROJECT, 2024
** my_navy.c
** File description:
** uwu
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/my_navy.h"

volatile sig_atomic_t signal_received = 0;

int get_nbr(char *av)
{
    int number = 0;
    int i = 0;

    while (av[i] != '\0') {
        number = number * 10 + (av[i] - '0');
        i++;
    }
    return number;
}

void handle_signal(int sig_no)
{
    if (sig_no == SIGUSR1) {
        signal_received = 1;
    }
}

char **init_map(char **map)
{
    int i = 0;

    map = malloc(sizeof(char *) * 10);
    for (; i < 10; i++)
        map[i] = malloc(sizeof(char) * 19);
    my_strcpy(map[0], " |A B C D E F G H");
    my_strcpy(map[1], "-+---------------");
    my_strcpy(map[2], "1|. . . . . . . .");
    my_strcpy(map[3], "2|. . . . . . . .");
    my_strcpy(map[4], "3|. . . . . . . .");
    my_strcpy(map[5], "4|. . . . . . . .");
    my_strcpy(map[6], "5|. . . . . . . .");
    my_strcpy(map[7], "6|. . . . . . . .");
    my_strcpy(map[8], "7|. . . . . . . .");
    my_strcpy(map[9], "8|. . . . . . . .");
    return map;
}

char **intermediate_for(char **map, char *path, int i)
{
    int row = path[i + 1] - 47;
    int col = (path[i] - 65) * 2 + 2;

    for (; row <= path[i + 4] - 47; row++) {
        map[row][(path[i] - 65) * 2 + 2] = path[i - 2];
        for (; col <= (path[i + 3] - 65) * 2 + 2; col += 2)
            map[row][col] = path[i - 2];
    }
    return map;
}

char **customize_map(char **map, char *path)
{
    int i = 2;

    for (; i < strlen(path); i += 8)
        if (path[i] >= 'A' && path[i] <= 'Z')
            map = intermediate_for(map, path, i);
    return map;
}

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
    // if (fd == -1)
    //     return(84);
    state = read(fd, buf, st.st_size);
    // if (buf[0] == '\0')
    //     return(84);
    close(fd);
    map = customize_map(map, buf);
    return map;
    // return 0;
}

void exe_player1(char *path, first_t *navy)
{
    pid_t pid_joueur1 = getpid();
    int i = 0;

    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    printf("my_pid: %d\n\n", pid_joueur1);
    signal(SIGUSR1, handle_signal);
    printf("waiting for enemy connection...\n\n");
    while (!signal_received)
        usleep(100000);
    printf("enemy connected\n\n");
    navy->my_map = read_file(path, navy->my_map);
    printf("my navy:\n");
    for (; i < 10; i++)
        printf("%s\n", navy->my_map[i]);
    printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        printf("%s\n", navy->enemy_map[k]);
}

int exe_player2(pid_t pid_player1, char *argument, second_t *navy)
{
    pid_t pid = getpid();
    int i = 0;

    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    printf("my_pid: %d\n\n", pid, pid_player1);
    usleep(100000);
    if (kill(pid_player1, SIGUSR1) == -1) {
        printf("Erreur\n");
        return (84);
    }
    printf("successfully connected\n");
    navy->my_map = read_file(argument, navy->my_map);
        printf("\nmy navy:\n");
    for (; i < 10; i++)
        printf("%s\n", navy->my_map[i]);
    printf("\nenemy navy:\n");
    for (int k = 0; k < 10; k++)
        printf("%s\n", navy->enemy_map[k]);
}

int main(int argc, char *argv[])
{
    pid_t pid_joueur;
    first_t *first = malloc(sizeof(first_t));
    second_t *second = malloc(sizeof(second));

    if (argc == 2) {
        exe_player1(argv[1], first);
    } else {
        pid_joueur = get_nbr(argv[1]);
        exe_player2(pid_joueur, argv[2], second);
    }
    return 0;
}
