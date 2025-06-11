/*
** EPITECH PROJECT, 2025
** Epi-Template-C
** File description:
** asm
*/

#include "../include/my.h"
#include "../include/ansi_color_code.h"
#include "../include/corewar.h"

int ends_with_s(const char *filename)
{
    int length;

    if (filename == NULL) {
        return 84;
    }
    length = my_strlen(filename);
    if (length < 2) {
        return 84;
    }
    if (my_strcmp(filename + length - 2, ".s") == 0) {
        return 0;
    }
    return 84;
}
