/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** check_map
*/

#include "../include/navy.h"

int check_ship_char_one(char **tab)
{
    int i = 0;

    while (i != 3) {
        if (tab[i][0] != (50 + i)) {
            write(2, "Error character one of text file for ship\n", 43);
            return (84);
        }
        i = i + 1;
    }
    return (0);
}

int check_ship_two_dot(char **tab)
{
    int i = 0;

    while (i != 3) {
        if (tab[i][1] != ':' && tab[i][4] != ':' && tab[i][7] != ':') {
            write(2, "Error for the dot between coordinates\n", 39);
            return (84);
        }
        i = i + 1;
    }
    return (0);
}

int check_ship_letter(char **tab)
{
    int i = 0;

    while (i != 3) {
        if (tab[i][2] < 'A' || tab[i][2] > 'H') {
            write(2, "Error first letter of coordinates of ship map\n", 47);
            return (84);
        } else if (tab[i][5] < 'A' || tab[i][5] > 'H') {
            write(2, "Error second letter of coordinates of ship map\n", 48);
            return (84);
        }
        i = i + 1;
    }
    return (0);
}

int check_ship_number(char **tab)
{
    int i = 0;

    while (i != 3) {
        if (tab[i][3] < '1' || tab[i][3] > '8') {
            write(2, "Error first number of coordinates of ship map\n", 47);
            return (84);
        } else if (tab[i][6] < '1' || tab[i][6] > '8') {
            write(2, "Error second number of coordinates of ship map\n", 48);
            return (84);
        }
        i = i + 1;
    }
    return (0);
}

int check_different(char **tab)
{
    int i = 0;

    while (i != 3) {
        if (tab[i][2] != tab[i][5] && tab[i][3] != tab[i][6]) {
            write(2, "Error letters and numbers are different ", 41);
            write(2, "diagonals ship is not good\n", 28);
            return (84);
        }
        i = i + 1;
    }
    return (0);
}