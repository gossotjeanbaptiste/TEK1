/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** Main for Epi-Template-C
*/
#include "include/my.h"
#include "include/ansi_color_code.h"
#include "include/call.h"
#include "include/struct.h"

int main(int ac, char **av)
{
    map_t map;

    if (ac != 2)
        return 84;
    setting_up(av[1], &map);
    return 0;
}
