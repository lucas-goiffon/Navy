/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "../include/navy.h"

int check_ship_main(char **tab)
{
    if (check_ship_char_one(tab) == 84 || check_ship_letter(tab) == 84)
        return (84);
    if (check_ship_number(tab) == 84 || check_ship_two_dot(tab) == 84)
        return (84);
    if (check_different(tab) == 84)
        return (84);
    return (0);
}

int init_map_second(navy_t *na, char *str)
{
    char **tab;

    if ((tab = create_map(na, str)) == NULL) {
        write(2, "Error malloc for tab ship or create map\n", 41);
        return (84);
    }
    if (create_map_sec(na) == 84) {
        write(2, "Error malloc create map second\n", 32);
        return (84);
    }
    if (check_ship_main(tab) == 84)
        return (84);
    return (0);
}

int init_map(int argc, char **argv, navy_t *na)
{
    char *str;
    char *filepath;

    if ((filepath = search_filepath(argv, argc)) == NULL) {
        write(2, "Wrong arguments number try ./navy -h\n", 38);
        return (84);
    }
    if ((str = reading(filepath)) == NULL) {
        write(2, "Error reading map text file\n", 29);
        return (84);
    }
    if (init_map_second(na, str) == 84)
        return (84);
    return (0);
}