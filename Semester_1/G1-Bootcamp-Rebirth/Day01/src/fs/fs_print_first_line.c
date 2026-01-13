/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** fs_print_first_line
*/

#include "../../include/my.h"
#include <fcntl.h>

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int i = 0;

    if (fd == -1) {
        return;
    }
    while (read(fd, buffer, 1) > 0) {
        if (buffer[0] == '\n') {
            break;
        }
        my_putchar(buffer[0]);
    }
    close(fd);
}
