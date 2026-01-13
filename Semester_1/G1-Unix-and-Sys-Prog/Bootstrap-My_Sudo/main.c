/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** Main for Epi-Template-C
*/
#include "include/my.h"
#include "include/include.h"

int main(int argc, char **argv)
{
    if (argc < 3)
        return 84;
    my_exec(argv[1], argv[2]);
}
