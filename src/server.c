/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** server
*/

#include "../include/navy.h"

pid_t init_server(pid_t pid_e)
{
    struct sigaction sa;

    my_printf("waiting for enemy connection...\n\n");
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    pid_e = bit(COLLECT);
    my_printf("enemy connected\n\n");
    my_kill(pid_e, SIGUSR1);
    return (pid_e);
}

int server_part(pid_t pid, pid_t pid_e, navy_t *na)
{
    char *str = malloc(sizeof(char) * 3);
    int r = 0;

    if (str == NULL)
        return (84);
    pid_e = init_server(pid_e);
    display_map(na);
    while (1) {
        if ((r = is_win_server(pid_e, na, str)) >= 0)
            return (r);
        display_map(na);
    }
}