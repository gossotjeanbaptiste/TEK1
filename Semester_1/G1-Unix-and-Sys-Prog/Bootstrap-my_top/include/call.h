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
struct getloadavg_s {
    FILE *file;
    char *line;
    size_t len;
    ssize_t read;
    int i;
    char *token;
    double *output;
};
int my_getloadavg(double loadavg[], int nelem,
    struct getloadavg_s *getloadavg_t);
void loop(struct getloadavg_s *getloadavg_t, double loadavg[], int nelem);
int verif(int nelem, struct getloadavg_s *getloadavg_t);
void display_load_average(void);
int verif_display(char *loadavg_str);
#endif
