/*
** EPITECH PROJECT, 2025
** Epi-Template-C
** File description:
** my_sudo
*/

#include <stdio.h>
#include <dirent.h>
#include "../include/ansi_color_code.h"
#include "../include/my_sudo.h"
#include "../include/my.h"

int error_file(FILE *file)
{
    if (file == NULL) {
        perror("Error while opening file");
        return 84;
    }
    return 0;
}

int error_dir(DIR *dir)
{
    if (dir == NULL) {
        perror("Error while opening folder");
        return 84;
    }
    return 0;
}

int error_handling(FILE *file, DIR *dir)
{
    if (file == NULL) {
        perror("Error while opening file");
        return 84;
    }
    if (dir == NULL) {
        perror("Error while opening folder");
        return 84;
    }
    return 0;
}
