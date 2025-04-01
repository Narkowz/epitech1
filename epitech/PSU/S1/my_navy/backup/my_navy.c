/*
** EPITECH PROJECT, 2024
** my_navy.c
** File description:
** uwu
*/

#include "include/my.h"
#include "include/my_navy.h"

global_t global = {0};

void get_pid(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1 || sig == SIGUSR2) {
            global.is_running = 1;
            global.opponent_pid = info->si_pid;
    }
}

void notify_opponent(pid_t opponent_pid, int signal)
{
    int i = 0;

    mini_printf("send signal %d %d\n", opponent_pid, signal);
    // for (int i = 0; msg[i] != -1; i++);
    // for (int k = i -1; k >= 0; k--) {
    //     if (msg[k] == 0)
    //         kill(opponent_pid, SIGUSR1);
    //     else
    //         kill(opponent_pid, SIGUSR2);
    kill(opponent_pid, signal);
}

void player_turn_handler(int signum)
{
    if (signum == SIGUSR1)
        global.player_turn = 0;
    if (signum == SIGUSR2)
        global.player_turn = 1;
}

int send_message(pid_t opponent_pid)
{
    char *message = NULL;
    size_t len = 0;
    ssize_t read;

    mini_printf("Attack: ");
    read = getline(&message, &len, stdin);
    int_to_binary(message);
    notify_opponent(opponent_pid, SIGUSR2);
    free(message);
}

static void exe_player1(char *path, first_t *navy)
{
    struct sigaction action = {0};

    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    mini_printf("my_pid: %d\n\n", getpid());
    action.sa_handler = get_pid;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    mini_printf("waiting for enemy connection...\n\n");
    while (!global.is_running)
        usleep(100000);
    mini_printf("enemy connected\n\n");
    start_game1(path, &action, navy);
}

static int exe_player2(pid_t pid_player1, char *argument, second_t *navy,
    pid_t *pid_player2)
{
    struct sigaction action = {0};

    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    mini_printf("my_pid: %d\n\n", getpid());
    usleep(100000);
    action.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &action, NULL);
    if (kill(pid_player1, SIGUSR1) == -1)
        return 84;
    mini_printf("successfully connected\n");
    start_game2(argument, &action, navy, pid_player1);
    return 0;
}

int main(int argc, char *argv[])
{
    pid_t pid_joueur;
    first_t *first = malloc(sizeof(first_t));
    second_t *second = malloc(sizeof(second_t));

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (argc == 2 && test_file(argv[1]) == 0) {
        exe_player1(argv[1], first);
    } else if (test_file(argv[2]) == 0) {
        pid_joueur = get_nbr(argv[1]);
        exe_player2(pid_joueur, argv[2], second, &global.opponent_pid);
    }
    return 84;
}
