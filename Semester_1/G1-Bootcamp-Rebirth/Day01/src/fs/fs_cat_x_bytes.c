/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** fs_cat_x_bytes
*/

#include "../../include/my.h"
#include <fcntl.h>

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[x];
    int return_int = read(fd, buffer, x);

    if (return_int > x) {
        return;
    }
    for (int i = 0; i < x; i++) {
        write(1, &buffer[i], 1);
    }
    close(fd);
    return 0;
}
