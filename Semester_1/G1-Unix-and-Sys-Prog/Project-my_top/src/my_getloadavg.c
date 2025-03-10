/*
** EPITECH PROJECT, 2025
** Project-my_top
** File description:
** my_getloadavg
*/

#include "../include/my.h"
#include "../include/call.h"

int my_getloadavg(void)
{
    double loadavg[3];
    FILE *file;

    file = fopen("/proc/loadavg", "r");
    if (file == NULL)
        return 84;
    if (fscanf(file, "%lf %lf %lf",
        &loadavg[0], &loadavg[1], &loadavg[2]) != 3) {
        fclose(file);
        return 84;
    }
    fclose(file);
    printw("load average: %.2lf %.2lf %.2lf",
    loadavg[0], loadavg[1], loadavg[2]);
    return 0;
}
