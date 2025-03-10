/*
** EPITECH PROJECT, 2025
** Project-my_top
** File description:
** main
*/
#include "include/my.h"
#include "include/call.h"

int main(void)
{
    int ch = 0;

    start();
    curs_set(FALSE);
    timeout(3000);
    while (1) {
        clear();
        print_header_top();
        refresh();
        ch = getch();
        if (ch == 'q') {
            break;
        }
    }
    endwin();
    curs_set(TRUE);
}
