/*
** EPITECH PROJECT, 2024
** Bootstrap-my_top
** File description:
** ncurses_init
*/

#include <curses.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/call.h"

void display_load_average(void)
{
    double loadavg[3];
    struct getloadavg_s getloadavg_t;
    char *loadavg_str = malloc(50 * sizeof(char));
    int ch;
    int row;
    int col;

    if (verif_display(loadavg_str) == -1)
        return;
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    getmaxyx(stdscr, row, col);
    nodelay(stdscr, TRUE);
    while (1) {
        my_getloadavg(loadavg, 3, &getloadavg_t);
        snprintf(loadavg_str, 50,
        "Load Average: %.2f, %.2f, %.2f", loadavg[0], loadavg[1], loadavg[2]);
        clear();
        mvprintw(row / 2, (col - my_strlen(loadavg_str)) / 2, "%s", loadavg_str);
        refresh();
        ch = getch();
        if (ch == 'q') {
            break;
        }
        usleep(100000);
    }

    endwin();
    curs_set(TRUE);
    free(loadavg_str);
}

int verif_display(char *loadavg_str)
{
    if (loadavg_str == NULL) {
        endwin();
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    return 0;
}
