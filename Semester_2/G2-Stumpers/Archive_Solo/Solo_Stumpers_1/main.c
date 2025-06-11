/*
** EPITECH PROJECT, 2025
** clean string (solo stumpers 1)
** File description:
** main
*/
#include "include/my.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        write(1, "\n", 1);
        return 0;
    } else if (argc == 2) {
        clean_str(argv[2]);
    } else {
        return 84;
    }
    return 0;
}
