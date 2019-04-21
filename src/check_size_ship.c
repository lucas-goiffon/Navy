/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** check_size_ship
*/

#include "../include/navy.h"

int verif_size_two(char **tab)
{
    int stock = 0;

    if (tab[0][2] == tab[0][5]) {
        stock = tab[0][6] - tab[0][3];
        if (stock != 1)
            return (84);
    } else {
        stock = tab[0][5] - tab[0][2];
        if (stock != 1)
            return (84);
    }
    return (0);
}

int verif_size_three(char **tab)
{
    int stock = 0;

    if (tab[1][2] == tab[1][5]) {
        stock = tab[1][6] - tab[1][3];
        if (stock != 2)
            return (84);
    } else {
        stock = tab[1][5] - tab[1][2];
        if (stock != 2)
            return (84);
    }
    return (0);
}

int verif_size_four(char **tab)
{
    int stock = 0;

    if (tab[2][2] == tab[2][5]) {
        stock = tab[2][6] - tab[2][3];
        if (stock != 3)
            return (84);
    } else {
        stock = tab[2][5] - tab[2][2];
        if (stock != 3)
            return (84);
    }
    return (0);
}

int verif_size_five(char **tab)
{
    int stock = 0;

    if (tab[3][2] == tab[3][5]) {
        stock = tab[3][6] - tab[3][3];
        if (stock != 4)
            return (84);
    } else {
        stock = tab[3][5] - tab[3][2];
        if (stock != 4)
            return (84);
    }
    return (0);
}