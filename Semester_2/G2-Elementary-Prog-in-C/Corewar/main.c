/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** main
*/

#include <stdlib.h>
#include "include/corewar.h"
#include "include/my.h"

static int show_help(int argc, char **argv)
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        mini_printf("USAGE\n"
        "./corewar [-dump nbr_cycle] [[-n prog_number] "
        "[-a load_address] prog_name] ...\n"
        "DESCRIPTION\n"
        "-dump nbr_cycle\t: dumps memory after that many cycles\n"
        "-n prog_number\t: sets the program’s number (ID)\n"
        "-a load_address\t: sets the load address in memory\n");
        return 0;
    }
    return 84;
}

int main(int argc, char **argv)
{
    global_t global = {-1, 0, CYCLE_TO_DIE, NULL, NULL, -1, 0, NULL};

    if (show_help(argc, argv) == 1)
        return 0;
    global.memory = malloc(sizeof(int) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        global.memory[i] = 0;
    manage_args(argc, argv, &global);
    place_progs(&global);
    use_cycle_loop(&global);
    remove_all_progs(&global);
    free(global.memory);
    free(global.progs);
    return 0;
}
