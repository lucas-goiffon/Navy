/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** put_ship
*/

#include "../include/navy.h"

void put_ship_size_two(navy_t *na, char **tab)
{
    int stock = 0;
    int stock_sec = 0;
    int stock_third = 0;

    if (tab[0][2] == tab[0][5]) {
        stock = tab[0][2] - 65;
        stock_third = tab[0][3] - 49;
        stock_sec = tab[0][6] - 49;
        na->map_me[stock_third][stock * 2] = '2';
        na->map_me[stock_sec][stock * 2] = '2';
    } else {
        stock = tab[0][2] - 65;
        stock_sec = tab[0][5] - 65;
        stock_third = tab[0][3] - 49;
        na->map_me[stock_third][stock * 2] = '2';
        na->map_me[stock_third][stock_sec * 2] = '2';
    }
}

void put_ship_size_three(navy_t *na, char **tab)
{
    int stock = 0;
    int stock_sec = 0;
    int stock_third = 0;

    if (tab[1][2] == tab[1][5]) {
        stock = tab[1][2] - 65;
        stock_third = tab[1][3] - 49;
        stock_sec = tab[1][6] - 49;
        while (stock_third <= stock_sec) {
            na->map_me[stock_third][stock * 2] = '3';
            stock_third = stock_third + 1;
        }
    } else {
        stock = tab[1][2] - 65;
        stock_sec = tab[1][5] - 65;
        stock_third = tab[1][3] - 49;
        while (stock <= stock_sec) {
            na->map_me[stock_third][stock * 2] = '3';
            stock = stock + 1;
        }
    }
}

void put_ship_size_four(navy_t *na, char **tab)
{
    int stock = 0;
    int stock_sec = 0;
    int stock_third = 0;

    if (tab[2][2] == tab[2][5]) {
        stock = tab[2][2] - 65;
        stock_third = tab[2][3] - 49;
        stock_sec = tab[2][6] - 49;
        while (stock_third <= stock_sec) {
            na->map_me[stock_third][stock * 2] = '4';
            stock_third = stock_third + 1;
        }
    } else {
        stock = tab[2][2] - 65;
        stock_sec = tab[2][5] - 65;
        stock_third = tab[2][3] - 49;
        while (stock <= stock_sec) {
            na->map_me[stock_third][stock * 2] = '4';
            stock = stock + 1;
        }
    }
}

void put_ship_size_five(navy_t *na, char **tab)
{
    int stock = 0;
    int stock_sec = 0;
    int stock_third = 0;

    if (tab[3][2] == tab[3][5]) {
        stock = tab[3][2] - 65;
        stock_third = tab[3][3] - 49;
        stock_sec = tab[3][6] - 49;
        while (stock_third <= stock_sec) {
            na->map_me[stock_third][stock * 2] = '5';
            stock_third = stock_third + 1;
        }
    } else {
        stock = tab[3][2] - 65;
        stock_sec = tab[3][5] - 65;
        stock_third = tab[3][3] - 49;
        while (stock <= stock_sec) {
            na->map_me[stock_third][stock * 2] = '5';
            stock = stock + 1;
        }
    }
}

int put_ship(navy_t *na, char **tab)
{
    if (verif_size_two(tab) == 84 || verif_size_three(tab) == 84) {
        write(2, "Error size ship 2 or 3\n", 24);
        return (84);
    } else if (verif_size_four(tab) == 84 || verif_size_five(tab) == 84) {
        write(2, "Error size ship 4 or 5\n", 24);
        return (84);
    }
    put_ship_size_two(na, tab);
    put_ship_size_three(na, tab);
    put_ship_size_four(na, tab);
    put_ship_size_five(na, tab);
    return (0);
}