/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** tools
*/

#include "../include/navy.h"

void get_pid(int sig, siginfo_t *info, void *context)
{
    static pid_t pid_e = 0;

    if (pid_e == 0) {
        bit(info->si_pid);
        pid_e = info->si_pid;
    }
    else if (pid_e == info->si_pid) {
        if (sig == SIGUSR1) {
            bit(1);
        } else if (sig == SIGUSR2) {
            bit(0);
        }
    }
}

int my_kill(pid_t pid, int sig)
{
    usleep(5000);
    if (kill(pid, sig) != 0) {
        my_printf("Connection lost\n");
        return (84);
    } else
        return (0);
}

int check_second_win(char **tab, int j, int k)
{
    if (tab[j][k] >= '2' && tab[j][k] <= '5' && tab[j][k] != ' ')
        return (1);
    return (0);
}

int check_win(char **tab)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (j < 8) {
        while (k < 16) {
            i = check_second_win(tab, j, k) + i;
            k = k + 1;
        }
        k = 0;
        j = j + 1;
    }
    if (i > 0)
        return (1);
    else
        return (0);
}