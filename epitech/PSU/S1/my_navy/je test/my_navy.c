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
            global.connected = 1;
            global.opponent_pid = info->si_pid;
    }
}

void notify_opponent(pid_t opponent_pid, int signal)
{
    kill(opponent_pid, signal);
}

void player_turn_handler(int signum)
{
    if (signum == SIGUSR1)
        global.player_turn = 1;
    if (signum == SIGUSR2)
        global.player_turn = 0;
}

static void test_answer(char *message, int *valid_input)
{
    size_t message_len = my_strlen(message);

    if (message_len > 0 && message[message_len - 1] == '\n')
        message[message_len - 1] = '\0';
    if (my_strlen(message) == 2 &&
        message[0] >= 'A' && message[0] <= 'H' &&
        message[1] >= '1' && message[1] <= '8') {
        *valid_input = 1;
    } else
        mini_printf("\nwrong position\n\n");
}

void send_message(pid_t opponent_pid)
{
    char *message = NULL;
    size_t len = 0;
    int valid_input = 0;

    do {
        mini_printf("attack: ");
        if (getline(&message, &len, stdin) != -1)
            test_answer(message, &valid_input);
    } while (!valid_input);
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
    while (!global.connected)
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
