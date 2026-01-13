/*
** EPITECH PROJECT, 2025
** solo stumper 2
** File description:
** main
*/
#include "include/my.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Error: not enough arguments.\n", 30);
        return 84;
    } else if (anagram(av[1], av[2]) == 84) {
        return 0;
    }
    return 0;
}
