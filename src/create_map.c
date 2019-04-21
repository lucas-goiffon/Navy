/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** create_map
*/

#include "../include/navy.h"

void verif_space_map(int i, int j, navy_t *na)
{
    if ((i % 2) == 0)
        na->map_me[j][i] = '.';
    else
        na->map_me[j][i] = ' ';
}

char **create_map(navy_t *na, char *str)
{
    int i = 0;
    int j = 0;
    char **tab;

    if ((na->map_me = malloc(sizeof(char *) * 8)) == NULL)
        return (NULL);
    while (j < 8) {
        if ((na->map_me[j] = malloc(sizeof(char) * 16)) == NULL)
            return (NULL);
        while (i < 15) {
            verif_space_map(i, j, na);
            i = i + 1;
        }
        na->map_me[j][i] = '\0';
        i = 0;
        j = j + 1;
    }
    if ((tab = str_tab_ship(str, na)) == NULL || put_ship(na, tab) == 84)
        return (NULL);
    return (tab);
}

void verif_space_map_sec(int i, int j, navy_t *na)
{
    if ((i % 2) == 0)
        na->map_ennemy[j][i] = '.';
    else
        na->map_ennemy[j][i] = ' ';
}

int create_map_sec(navy_t *na)
{
    int i = 0;
    int j = 0;

    if ((na->map_ennemy = malloc(sizeof(char *) * 8)) == NULL)
        return (84);
    while (j < 8) {
        if ((na->map_ennemy[j] = malloc(sizeof(char) * 16)) == NULL)
            return (84);
        while (i < 15) {
            verif_space_map_sec(i, j, na);
            i = i + 1;
        }
        na->map_ennemy[j][i] = '\0';
        i = 0;
        j = j + 1;
    }
    return (0);
}