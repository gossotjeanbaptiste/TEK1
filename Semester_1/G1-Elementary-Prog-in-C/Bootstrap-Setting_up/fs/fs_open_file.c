/*
** EPITECH PROJECT, 2024
** B-CPE-110-bssettingup-NCY-1-1-jean-baptiste.gossot
** File description:
** fs_open_file
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../include/call.h"
#include "../include/my.h"

int fs_open_file(char const *filepath)
{
    if (open(filepath, O_RDONLY) == -1) {
        my_putstr("FAILURE\n");
        return open(filepath, O_RDONLY);
    }
    my_putstr("SUCCESS\n");
    return open(filepath, O_RDONLY);
}
