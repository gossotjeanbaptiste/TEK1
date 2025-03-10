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
    if (ac == 1) {
        var_declaration();
    } else if (av[1][0] == '-' && av[1][1] == 'h') {
        mini_printf(MAG"Bootstrap My_Radar: \n"
        BRED"\tGame type : Simulation of airline traffic \n"
        BLU"\tInspired Game : Not known \n"
        GRN"\tCreated by Jean-Baptiste GOSSOT, Epitech Nancy PGE 2029\n"
        BGRN"\t©JustWirelessInc. 2021-2029\n"COLOR_RESET);
    } else {
        mini_printf(BRED"Unknown argument, please use '-h' for complementary "
        "information.\n"
        "To start the game please do './my_hunter'.\n"COLOR_RESET);
    }
    return 0;
}