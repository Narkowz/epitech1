#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

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

void gestionnaire_signal(int signal_num, siginfo_t *info, void *context) {
    // Récupérer le PID de l'émetteur du signal
    pid_t pid_emetteur = info->si_pid;

    printf("Signal %d reçu de la part du processus avec PID %d.\n", signal_num, pid_emetteur);
    kill(pid_emetteur, SIGUSR1);
}

int main(int ac, char **av) {
    if (ac == 2) {
        pid_t pid = get_nbr(av[1]);
        printf("test %d\n", pid);
        kill(pid, SIGUSR2);
    }
    struct sigaction sa;

    // Configurer le gestionnaire de signal pour utiliser siginfo_t
    sa.sa_sigaction = gestionnaire_signal;
    sa.sa_flags = SA_SIGINFO;

    // Appliquer le gestionnaire de signal
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("Erreur lors de la configuration du gestionnaire de signal");
        return 1;
    }
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Erreur lors de la configuration du gestionnaire de signal");
        return 1;
    }

    printf("Le PID de ce processus est : %d\n", getpid());

    // Attendre les signaux
    while (1) {
        sleep(1);  // Ajoutez une pause pour éviter la consommation excessive de CPU
    }

    return 0;
}
