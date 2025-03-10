/*
** EPITECH PROJECT, 2025
** Project-my_top
** File description:
** count_task
*/

#include "../../include/my.h"
#include "../../include/call.h"
int count_tasks(void)
{
    struct dirent *PID;
    int count = 0;
    DIR *dir = opendir("/proc/");

    if (dir == NULL)
        return 84;
    PID = readdir(dir);
    while (PID != NULL) {
        if (isdigit(PID->d_name[0]))
            count++;
        PID = readdir(dir);
    }
    closedir(dir);
    printw("\nTasks: %d total,", count);
    return 0;
}
