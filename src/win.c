/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** win
*/

#include "../include/navy.h"

int is_win_server(pid_t pid_e, navy_t *na, char *str)
{
    if (attack(str, na, pid_e) == 84)
        return (0);
    str = my_strcpy(str, "@0");
    pause();
    if (bit(COLLECT) == 0) {
        display_map(na);
        my_printf("I won\n");
        return (0);
    }
    waiting_attack(str, na, pid_e);
    if (check_win(na->map_me) == 0) {
        usleep(5000);
        kill(pid_e, SIGUSR2);
        display_map(na);
        my_printf("Enemy won\n");
        return (1);
    } else {
        my_kill(pid_e, SIGUSR1);
    }
    return (-1);
}

int is_win_client(pid_t pid_e, navy_t *na, char *str)
{
    str = my_strcpy(str, "@0");
    if (waiting_attack(str, na, pid_e) == 84)
        return (0);
    if (check_win(na->map_me) == 0) {
        usleep(5000);
        kill(pid_e, SIGUSR2);
        display_map(na);
        my_printf("Enemy won\n");
        return (1);
    } else {
        my_kill(pid_e, SIGUSR1);
    }
    if (attack(str, na, pid_e) == 84)
        return (0);
    pause();
    if (bit(COLLECT) == 0) {
        display_map(na);
        my_printf("I won\n");
        return (0);
    }
    return (-1);
}