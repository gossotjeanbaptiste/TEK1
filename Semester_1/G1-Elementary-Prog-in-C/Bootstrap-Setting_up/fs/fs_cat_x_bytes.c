/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** fs_cat_x_bytes -> display x bytes of a file
*/
#include <fcntl.h>
#include "../include/call.h"
#include "../include/my.h"

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[x];
    int return_integer = read(fd, buffer, x);

    if (return_integer > x) {
        return 84;
    }
    for (int i = 0; i < x; i++) {
        write(1, &buffer[i], 1);
    }
    close(fd);
    return 0;
}
