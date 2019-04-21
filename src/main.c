/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** main
*/

#include "../include/navy.h"

int bit(int add)
{
    static int nb = -1;

    if (add != COLLECT)
        nb = add;
    return (nb);
}

void destroys(navy_t *na)
{
    for (int i = 0; i < 8; i = i + 1) {
        free(na->map_me[i]);
        free(na->map_ennemy[i]);
    }
    free(na->map_me);
    free(na->map_ennemy);
    free(na);
}

int main(int ac, char **av)
{
    pid_t pid = getpid();
    pid_t pid_e;
    navy_t *na;
    int r = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf(HELP);
        return (0);
    } else if ((na = init_game(ac, av)) == NULL)
        return (84);
    my_printf("my_pid: %d\n", pid);
    if (ac == 2) {
        r = server_part(pid, pid_e, na);
    } else if (ac == 3) {
        pid_e = my_getnbr(av[1]);
        r = client_part(pid, pid_e, na);
    } else
        return (84);
    destroys(na);
    return (r);
}