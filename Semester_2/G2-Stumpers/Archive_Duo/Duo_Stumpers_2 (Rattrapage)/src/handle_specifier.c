/*
** EPITECH PROJECT, 2025
** stumper
** File description:
** handle_specifier
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/graphic_art.h"

static int verify_characters(const int index, const int ac,
    const char *const av[])
{
    if (index + 1 >= ac)
        return 0;
    if (index + 1 < ac) {
        if (strcmp(av[index + 1], "-n") == 0)
            return 0;
        if (strcmp(av[index + 1], "-s") == 0)
            return 0;
    }
    for (int i = 0; av[index + 1][i]; i++)
        if (!isprint(av[index + 1][i]))
            return 0;
    return 1;
}

static int verify_number(const int index, const int ac,
    const char *const av[])
{
    if (index + 1 >= ac)
        return 0;
    if (index + 1 < ac) {
        if (!strcmp(av[index + 1], "-n"))
            return 0;
        if (!strcmp(av[index + 1], "-s"))
            return 0;
    }
    for (int i = 0; av[index + 1][i]; i++) {
        if (!isdigit(av[index + 1][i]))
            return 0;
    }
    return 1;
}

void handle_specifier(const int ac, const char *const av[],
    flag_t *flags)
{
    flags->flag_n = NULL;
    flags->flag_s = NULL;
    for (int i = 1; i < ac; i++) {
        if (!strcmp(av[i], "-n") && verify_number(i, ac, av)) {
            flags->flag_n = (char *)av[i + 1];
            i++;
        }
        if (!strcmp(av[i], "-s") && verify_characters(i, ac, av)) {
            flags->flag_s = (char *)av[i + 1];
            i++;
        }
    }
}
