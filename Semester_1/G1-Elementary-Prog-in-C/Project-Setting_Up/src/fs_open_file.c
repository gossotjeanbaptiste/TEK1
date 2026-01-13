/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** fs_open_file
*/

#include "../include/my.h"
#include <fcntl.h>

int fs_open_file(char const *filepath)
{
    if (open(filepath, O_RDONLY) == -1) {
        mini_printf("FAILURE\n");
        return open(filepath, O_RDONLY);
    }
    mini_printf("SUCCESS\n");
    return open(filepath, O_RDONLY);
}
