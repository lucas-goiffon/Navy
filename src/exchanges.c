/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** exchanges
*/

#include "../include/navy.h"

void send_pos(char *str, pid_t pid_e)
{
    my_kill(pid_e, SIGUSR1);
    pause();
    for (int i = 64; i < str[0]; i = i + 1) {
        my_kill(pid_e, SIGUSR1);
        pause();
    }
    my_kill(pid_e, SIGUSR2);
    pause();
    for (int i = 48; i < str[1]; i = i + 1) {
        my_kill(pid_e, SIGUSR1);
        pause();
    }
    my_kill(pid_e, SIGUSR2);
}

char *receive_pos(pid_t pid_e, char *str)
{
    pause();
    my_kill(pid_e, SIGUSR1);
    if (bit(COLLECT) == 0)
        return (NULL);
    pause();
    while (bit(COLLECT) == 1) {
        str[0] = str[0] + 1;
        my_kill(pid_e, SIGUSR1);
        pause();
    }
    my_kill(pid_e, SIGUSR1);
    pause();
    while (bit(COLLECT) == 1) {
        str[1] = str[1] + 1;
        my_kill(pid_e, SIGUSR1);
        pause();
    }
    return (str);
}