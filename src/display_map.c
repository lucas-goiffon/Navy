/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** display_map
*/

#include "../include/navy.h"

void display_first_line(void)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
}

void display_map(navy_t *na)
{
    int i = 0;

    my_putstr("my positions:\n");
    display_first_line();
    while (i < 8) {
        my_printf("%d|%s\n", i + 1, na->map_me[i]);
        i = i + 1;
    }
    i = 0;
    my_putstr("\nenemy's positions:\n");
    display_first_line();
    while (i < 8) {
        my_printf("%d|%s\n", i + 1, na->map_ennemy[i]);
        i = i + 1;
    }
    my_putchar('\n');
}