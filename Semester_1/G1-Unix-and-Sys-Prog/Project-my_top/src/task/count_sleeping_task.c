/*
** EPITECH PROJECT, 2025
** Project-my_top
** File description:
** count_sleeping_task
*/

#include "../../include/my.h"
#include "../../include/call.h"

int count_sleeping_task(void)
{
    struct dirent *PID;
    int count = 0;
    DIR *dir = opendir("/proc/");

    if (dir == NULL)
        return 84;
    PID = readdir(dir);
    while (PID != NULL) {
        if (isdigit(PID->d_name[0]) && is_task_sleeping(PID->d_name))
            count++;
        PID = readdir(dir);
    }
    closedir(dir);
    printw("%d sleeping, ", count);
    return 0;
}

int is_task_sleeping(const char *pid)
{
    char path[512];
    FILE *fp;
    char state;

    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    fp = fopen(path, "r");
    if (fp == NULL)
        return 84;
    if (fscanf(fp, "%*d %*s %c", &state) != 1) {
        fclose(fp);
        return 84;
    }
    fclose(fp);
    return (state == 'S' || state == 'D' || state == 'P' || state == 'I');
}
