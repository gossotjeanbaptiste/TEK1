/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** get_argument_type
*/

#include "../../../include/corewar.h"

arg_type_t get_argument_type(global_t *global, int cmd_address, int arg)
{
    int cmd = global->memory[select_address(cmd_address)] - 1;
    int ocp = global->memory[select_address(cmd_address + 1)];
    int result = (ocp >> 6) & 3;
    int arg2 = (ocp >> 4) & 3;
    int arg3 = (ocp >> 2) & 3;

    if (arg == 2)
        result = arg2;
    if (arg == 3)
        result = arg3;
    for (int i = 0; i < 3; i++) {
        if (COMMANDS[cmd].args_types[i].arg1 == DIR4 ||
        COMMANDS[cmd].args_types[i].arg2 == DIR4 ||
        COMMANDS[cmd].args_types[i].arg3 == DIR4)
            result = (result == DIR2) ? DIR4 : result;
    }
    if (!COMMANDS[cmd].has_op_code || result == NO)
        return (COMMANDS[cmd].args_types[arg - 1].arg1);
    return result;
}
