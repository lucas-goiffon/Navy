/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** read_stock_ship
*/

#include "../include/navy.h"

char *reading(char *filepath)
{
    int fd = 0;
    int i = 0;
    char *str;
    char charac;
    size_t reading = 96;

    if ((str = malloc(sizeof(char) * 32)) == NULL)
        return (NULL);
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return (NULL);
    while (reading != 0) {
        reading = read(fd, &charac, 1);
        str[i] = charac;
        i = i + 1;
    }
    str[i - 1] = '\0';
    if (my_strlen(str) != 31 && my_strlen(str) != 32)
        return (NULL);
    close(fd);
    return (str);
}

char **str_tab_ship(char *str, navy_t *na)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab;

    if ((tab = malloc(sizeof(char *) * 4)) == NULL)
        return (NULL);
    while (i != 32) {
        if ((tab[j] = malloc(sizeof(char) * 8)) == NULL)
            return (NULL);
        while (str[i] != '\n' && str[i] != '\0') {
            tab[j][k] = str[i];
            i = i + 1;
            k = k + 1;
        }
        tab[j][k] = '\0';
        i = i + 1;
        k = 0;
        j = j + 1;
    }
    return (tab);
}

char *search_filepath(char **argv, int argc)
{
    if (argc == 2) {
        return (argv[1]);
    } else if (argc == 3) {
        return (argv[2]);
    }
    return (NULL);
}