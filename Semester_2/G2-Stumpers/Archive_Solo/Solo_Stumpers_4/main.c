/*
** EPITECH PROJECT, 2025
** solo stumper 3
** File description:
** main
*/
#include "include/my.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr("Usage: frenchNameFormatter string");
        return 84;
    } else {
        french_name_formatter(argv[1]);
    }
    return 0;
}
