/*
** EPITECH PROJECT, 2024
** Bootstrap-my_top
** File description:
** ncurses_init
*/

#include "../include/my.h"
#include "../include/call.h"

void start(void)
{
    initscr();
    cbreak();
    noecho();
}
