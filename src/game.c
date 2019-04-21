/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** game
*/

#include "../include/navy.h"

navy_t *init_game(int ac, char **av)
{
    navy_t *na;
    struct sigaction sa;

    if ((na = malloc(sizeof(navy_t))) == NULL)
        return (NULL);
    if ((init_map(ac, av, na)) == 84)
        return (NULL);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    return (na);
}

char *ask_for_attack(navy_t *na)
{
    char *str;

    my_printf("attack: ");
    str = get_next_line(0);
    if (str == NULL)
        return (NULL);
    else if ((str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8' ||
    str[2] != '\0')) {
        my_printf("wrong position\n");
        str = ask_for_attack(na);
    }
    return (str);
}

void is_touched(char *str, navy_t *na, pid_t pid_e)
{
    if (na->map_me[str[1] - 48 - 1][(str[0] - 65) * 2] != '.' &&
    na->map_me[str[1] - 48 - 1][(str[0] - 65) * 2] != 'o' &&
    na->map_me[str[1] - 48 - 1][(str[0] - 65) * 2] != 'x') {
        my_printf("hit\n\n");
        na->map_me[str[1] - 48 - 1][(str[0] - 65) * 2] = 'x';
        my_kill(pid_e, SIGUSR1);
    } else {
        my_printf("missed\n\n");
        if (na->map_me[str[1] - 48 - 1][(str[0] - 65) * 2] != 'x')
            na->map_me[str[1] - 48 - 1][(str[0] - 65) * 2] = 'o';
        my_kill(pid_e, SIGUSR2);
    }
}

int waiting_attack(char *str, navy_t *na, pid_t pid_e)
{
    my_printf("waiting for enemy's attack...\n");
    str = receive_pos(pid_e, str);
    if (str == NULL)
        return (84);
    my_printf("%s: ", str);
    is_touched(str, na, pid_e);
    return (0);
}

int attack(char *str, navy_t *na, pid_t pid_e)
{
    if ((str = ask_for_attack(na)) == NULL) {
        my_kill(pid_e, SIGINT);
        return (84);
    }
    usleep(5000);
    send_pos(str, pid_e);
    pause();
    if (bit(COLLECT) == 1) {
        my_printf("%s: hit\n\n", str);
        na->map_ennemy[str[1] - 48 - 1][(str[0] - 65) * 2] = 'x';
    } else {
        my_printf("%s: missed\n\n", str);
        if (na->map_ennemy[str[1] - 48 - 1][(str[0] - 65) * 2] != 'x')
            na->map_ennemy[str[1] - 48 - 1][(str[0] - 65) * 2] = 'o';
    }
    return (0);
}