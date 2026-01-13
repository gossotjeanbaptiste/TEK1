/*
** EPITECH PROJECT, 2024
** Bootstrap-my_top
** File description:
** call
*/

#ifndef INCLUDED_CALL_H
    #define INCLUDED_CALL_H
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <pwd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <grp.h>
    #include <fcntl.h>
    #include <sys/sysmacros.h>
    #include <curses.h>
    #include <sys/time.h>
    #include <sys/resource.h>
    #include <ncurses.h>
    #include <utmp.h>
    #include <fcntl.h>
    #include <ctype.h>
typedef enum {
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
    PETABYTE,
    EXABYTE
} unit_t;
double convert(double value, unit_t from, unit_t to);
void start(void);

// * Task functions
int count_tasks(void);
int count_running_task(void);
int is_task_running(const char *pid);
int count_sleeping_task(void);
int is_task_sleeping(const char *pid);
int count_zombie_task(void);
int is_task_zombie(const char *pid);
int count_stopped_task(void);
int is_task_stopped(const char *pid);


// * CPU Usage

typedef struct cpu_usage {
    float user;
    float system;
    float low_priority;
    float idle;
    float iowait;
    float irq;
    float softirq;
    float steal;
} cpu_usage_t;
cpu_usage_t get_cpu_usage(void);
void percentage_cpu_usage(void);

// * Display function
void print_header_top(void);
int verif_display(char *loadavg_str);
int my_getloadavg(void);

// * Time functions :
void print_actual_time(void);
int show_uptime(void);

// * Users functions :
int open_utmp_file(void);
int count_users(int utmpfd);
int print_user_count(int user_count);
int how_many_user(void);
#endif /* INCLUDED_CALL_H */
