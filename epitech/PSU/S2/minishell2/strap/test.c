#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char ***parse_commands(int argc, char **argv);
void execute_commands(int cmd_count, char ***cmds);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s 'cmd1 | cmd2 | ... | cmdN'\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char ***commands = parse_commands(argc, argv);
    int cmd_count = argc - 1;

    execute_commands(cmd_count, commands);

    // Cleanup
    for (int i = 0; i < cmd_count; i++) {
        for (int j = 0; commands[i][j] != NULL; j++) {
            free(commands[i][j]);
        }
        free(commands[i]);
    }
    free(commands);

    return 0;
}

void execute_commands(int cmd_count, char ***cmds)
{
    int i;
    int **pipes = malloc((cmd_count - 1) * sizeof(int *));
    for (i = 0; i < cmd_count - 1; i++) {
        pipes[i] = malloc(2 * sizeof(int));
        pipe(pipes[i]);
    }

    for (i = 0; i < cmd_count; i++) {
        pid_t pid = fork();
        if (pid == 0) { // Child process
            if (i > 0) { // Set up input from previous command
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }
            if (i < cmd_count - 1) { // Set up output for next command
                dup2(pipes[i][1], STDOUT_FILENO);
            }
            // Close all pipe fds
            for (int j = 0; j < cmd_count - 1; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }
            execve(cmds[i][0], cmds[i], (char *const *)NULL);
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }

    // Close all pipe fds in parent
    for (int j = 0; j < cmd_count - 1; j++) {
        close(pipes[j][0]);
        close(pipes[j][1]);
    }

    // Wait for all child processes
    for (i = 0; i < cmd_count; i++) {
        wait(NULL);
    }

    // Cleanup
    for (i = 0; i < cmd_count - 1; i++) {
        free(pipes[i]);
    }
    free(pipes);
}

char ***parse_commands(int argc, char **argv) {
    char ***commands = malloc((argc - 1) * sizeof(char **));
    int cmd_index = 0;
    for (int i = 1; i < argc; i++) {
        char *token = strtok(argv[i], "|");
        while (token != NULL) {
            char **cmd_args = malloc(10 * sizeof(char *));
            int arg_index = 0;
            char *arg_token = strtok(token, " ");
            while (arg_token != NULL) {
                cmd_args[arg_index] = strdup(arg_token);
                arg_index++;
                arg_token = strtok(NULL, " ");
            }
            cmd_args[arg_index] = NULL; // Null-terminate the array
            commands[cmd_index] = cmd_args;
            cmd_index++;
            token = strtok(NULL, "|");
        }
    }
    return commands;
}
