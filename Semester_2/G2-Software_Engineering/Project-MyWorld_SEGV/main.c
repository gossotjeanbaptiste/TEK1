/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** main
*/
#include "include/csfml_include.h"
#include "include/my.h"
#include "include/my_graphical.h"
#include "include/struct_fb.h"
#include "include/ansi_color_code.h"

int main(int ac, char **av)
{
    if (ac == 1 && my_strcmp(av[0], "./my_world") == 0) {
        return my_world();
    }
    if (my_strcmp(av[1], "-h") == 0) {
        mini_printf(MAG"Project: \n"
        BRED"\tGame type : To complete \n"
        BLU"\tInspired Game : Is there an inspired game ? \n"
        GRN"\tCreated by Jean-Baptiste GOSSOT, Epitech Nancy PGE 2029\n"
        BGRN"\t©JustWirelessInc. 2021-2029\n"COLOR_RESET);
    } else {
        mini_printf(BRED"Unknown argument, please use '-h' for complementary "
        "information.\n"
        "To start the game please do './my_hunter'.\n"COLOR_RESET);
    }
    return 0;
}
