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

void notify_opponent(pid_t opponent_pid, char *message)
{
    for (int i = 0; i <= message[0] - 64; i++) {
        printf("notify1\n");
        kill(opponent_pid, SIGUSR1);
        usleep(4000);
    }
            // printf("notify0.5\n");
    kill(opponent_pid, SIGUSR2);
            usleep(4000);
    for (int i = 0; i <= message[1] - 49; i++) {
            printf("notify2\n");
        kill(opponent_pid, SIGUSR1);
        usleep(4000);
    }
                // printf("notify3\n");
    kill(opponent_pid, SIGUSR2);
    // printf("out\n");
}

void player_turn_handler(int signum)
{
    printf("received %d\n", signum);
    if (signum == SIGUSR1)
        global.sig1++;
    if (signum == SIGUSR2)
        global.sig2++;
    if (global.sig2 == 1 && global.sig1 != 0) {
        printf("test");
        global.message[2] = '\0';
        global.message[0] = global.sig1 + 63;
        global.sig1 = 0;
        global.sig2 = 2;
        return;
    }
    if (global.sig2 == 3 && global.sig1 != 0) {
        printf("ici");
        global.message[1] = global.sig1 + 48;
        global.sig1 = 0;
        global.sig2 = 0;
        test_position();
        if (global.player_turn == 0)
            global.player_turn = 1;
        else
            global.player_turn = 0;
            return;
    }
    send_another_signal();
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
        printf("\nwrong position\n\n");
}

void send_message(pid_t opponent_pid)
{
    char *message = malloc(sizeof(char) * 4);
    size_t len = 1;
    int valid_input = 0;

    printf("\nattack: \n");
    do {
        len = read(0, message, 4);
        message[len] = '\0';
        test_answer(message, &valid_input);
        // printf("%s\n", message);
    } while (!valid_input);
    // printf("%d olala\n", valid_input);
    // printf("voici le message '%s'\n", message);
    global.message = my_strdup(message);
    notify_opponent(opponent_pid, message);
    free(message);
}

static void exe_player1(char *path, first_t *navy)
{
    struct sigaction action = {0};

    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    printf("my_pid: %d\n\n", getpid());
    action.sa_handler = get_pid;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    printf("waiting for enemy connection...\n\n");
    while (!global.connected)
        usleep(100000);
    printf("enemy connected\n\n");
    start_game1(path, &action, navy);
}

static int exe_player2(pid_t pid_player1, char *argument, second_t *navy,
    pid_t *pid_player2)
{
    struct sigaction action = {0};

    global.opponent_pid = pid_player1;
    navy->my_map = init_map(navy->my_map);
    navy->enemy_map = init_map(navy->enemy_map);
    printf("my_pid: %d\n\n", getpid());
    global.my_pid = getpid();
    usleep(100000);
    action.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &action, NULL);
    if (kill(pid_player1, SIGUSR1) == -1)
        return 84;
    printf("successfully connected\n");
    start_game2(argument, &action, navy, pid_player1);
    return 0;
}

int main(int argc, char *argv[])
{
    pid_t pid_joueur;
    global.first = malloc(sizeof(first_t));
    global.second = malloc(sizeof(second_t));
    global.message = malloc(sizeof(char) * 3);

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (argc == 2 && test_file(argv[1]) == 0) {
        exe_player1(argv[1], global.first);
    } else if (test_file(argv[2]) == 0) {
        pid_joueur = get_nbr(argv[1]);
        exe_player2(pid_joueur, argv[2], global.second, &global.opponent_pid);
    }
    return 84;
}
