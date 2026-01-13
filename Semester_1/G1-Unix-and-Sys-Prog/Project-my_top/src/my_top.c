/*
** EPITECH PROJECT, 2024
** Project-my_top
** File description:
** my_top
*/

#include "../include/my.h"
#include "../include/call.h"

void print_header_top(void)
{
    printw("top - ");
    print_actual_time();
    show_uptime();
    how_many_user();
    my_getloadavg();
    count_tasks();
    count_running_task();
    count_sleeping_task();
    count_stopped_task();
    count_zombie_task();
    percentage_cpu_usage();
}
