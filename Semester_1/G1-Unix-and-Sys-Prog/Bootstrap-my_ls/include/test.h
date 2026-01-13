/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-bsmyls-jean-baptiste.gossot
** File description:
** test
*/
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
#include <sys/sysmacros.h>

#ifndef INCLUDED_TEST_H
    #define INCLUDED_TEST_H
char type_file(mode_t mode);
char *get_perm(mode_t mode);
int info_file(char *file_name);
int main(int ac, char **av);
#endif
