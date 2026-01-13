/*
** EPITECH PROJECT, 2024
** Project-my_top
** File description:
** get_time
*/
#include "../include/my.h"
#include "../include/call.h"

void print_actual_time(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printw("%02d:%02d:%02d\t", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int show_uptime(void)
{
    double uptime;
    int converted_uptime;
    FILE *file;

    file = fopen("/proc/uptime", "r");
    if (file == NULL)
        return 84;
    if (fscanf(file, "%lf", &uptime) != 1) {
        fclose(file);
        return 84;
    }
    fclose(file);
    converted_uptime = (int)uptime;
    if (converted_uptime >= 86400)
        printw("up %d days, %d:%d", converted_uptime / 86400,
        (converted_uptime % 86400) / 3600, (converted_uptime % 3600) / 60);
    else
        printw("up %d:%d", (converted_uptime % 86400) / 3600,
        (converted_uptime % 3600) / 60);
    return 0;
}
