/*
** EPITECH PROJECT, 2024
** process_info.c
** File description:
** process_info
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t id;
    pid_t pid;
    pid_t pgid;

    id = getpid();
    pid = getppid();
    pgid = getpgid(id);
    printf("PID: %i\n", id);
    printf("PPID: %i\n", pid);
    printf("PGID: %i\n", pgid);
    return 0;
}
