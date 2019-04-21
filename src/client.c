/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** client
*/

#include "../include/navy.h"

int init_client(pid_t pid_e)
{
    if (kill(pid_e, SIGUSR1) == 0) {
        my_printf("successfully connected\n\n");
        pause();
        return (0);
    } else {
        my_printf("Connection failed.\n");
        return (84);
    }
}

int client_part(pid_t pid, pid_t pid_e, navy_t *na)
{
    char *str = malloc(sizeof(char) * 3);
    int r = 0;

    if (str == NULL)
        return (84);
    str[0] = 64;
    str[1] = 48;
    str[2] = '\0';
    if (init_client(pid_e) == 84)
        return (84);
    display_map(na);
    while (1) {
        if ((r = is_win_client(pid_e, na, str)) >= 0)
            return (r);
        display_map(na);
    }
}