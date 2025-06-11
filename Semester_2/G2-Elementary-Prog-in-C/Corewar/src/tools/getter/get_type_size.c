/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** get_type_size
*/

#include "../../../include/corewar.h"

int get_type_size(arg_type_t type)
{
    switch (type) {
    case REG:
        return T_REG;
        break;
    case IND:
        return T_IND;
        break;
    case DIR2:
        return T_DIR2;
        break;
    case DIR4:
        return T_DIR4;
        break;
    }
    return 0;
}
