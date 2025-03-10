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
    if (ac != 2) {
        return 0;
    } else if (ac == 2) {
        call_or_use(av);
    } else {
        mini_printf(BRED"Unknown argument, please use '-h' for complementary "
        "information.\n"
        "To start the game please do './my_hunter'.\n"COLOR_RESET);
        return 0;
    }
    return 84;
}

void call_or_use(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        mini_printf(MAG"My Radar: \n"
        BRED"\tGame type : Airplane Traffic Simulation \n"
        GRN"\tCreated by Jean-Baptiste GOSSOT, Epitech Nancy PGE 2029\n"
        BGRN"\t©JustWirelessInc. 2021-2029\n\n"COLOR_RESET
        "Air traffic simulation panel\n"
        "USAGE\n"
        "\t./my_radar [OPTIONS] path_to_script\n"
        "\tpath_to_script \t The path to script file.\n"
        "OPTIONS\n"
        "\t-h\t\t\t\t print the usage and quit."
        "USER INTERACTIONS\n"
        "\t'L' Key \t\tenable/disable hitboxes and areas.\n"
        "\t'S' Key \t\tenable/disable sprites.\n");
    } else {
        var_declaration(av[1]);
    }
}
