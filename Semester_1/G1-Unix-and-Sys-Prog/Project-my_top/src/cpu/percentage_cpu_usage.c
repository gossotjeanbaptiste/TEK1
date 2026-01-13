/*
** EPITECH PROJECT, 2025
** Project-my_top
** File description:
** percentage_cpu_usage
*/

#include "../../include/my.h"
#include "../../include/call.h"

cpu_usage_t get_cpu_usage(void)
{
    FILE *fp;
    char buffer[1024];
    cpu_usage_t usage = {0};

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return usage;
    }
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return usage;
    }
    sscanf(buffer, "cpu %f %*f %f %f %f %f %f %f %f",
        &usage.user, &usage.low_priority, &usage.system, &usage.idle,
        &usage.iowait, &usage.irq, &usage.softirq, &usage.steal);
    fclose(fp);
    return usage;
}

void percentage_cpu_usage(void)
{
    cpu_usage_t usage = get_cpu_usage();
    float total = usage.user + usage.low_priority + usage.system +
    usage.idle + usage.iowait + usage.irq + usage.softirq + usage.steal;

    printw("%%Cpu(s): %.1f us, ", (usage.user / total) * 100.0);
    printw("%.1f sy, ", (usage.system / total) * 100.0);
    printw("%.1f ni, ", (usage.low_priority / total) * 100.0);
    printw("%.1f id, ", (usage.idle / total) * 100.0);
    printw("%.1f wa, ", (usage.iowait / total) * 100.0);
    printw("%.1f hi, ", (usage.irq / total) * 100.0);
    printw("%.1f si, ", (usage.softirq / total) * 100.0);
    printw("%.1f st\n", (usage.steal / total) * 100.0);
}
