/*
** EPITECH PROJECT, 2024
** my_cat
** File description:
** reproduction the base function of cat
*/
#include "../include/my.h"
#include <fcntl.h>

void my_cat(char *text)
{
    my_putstr(text);
}

int main(int ac, char **av)
{
    char text = open(av[1][1], O_RDONLY);

    read(text);
    my_cat(text);
    return 0;
}
