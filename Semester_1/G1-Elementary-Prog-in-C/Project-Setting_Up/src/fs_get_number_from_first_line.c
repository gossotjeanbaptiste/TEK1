/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** fs_get_number_from_first_line
*/

#include "../include/my.h"
#include <fcntl.h>

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[256];
    int bytes_read;

    if (fd == -1) {
        return 84;
    }
    bytes_read = read(fd, buffer, 255);
    if (bytes_read <= 0) {
        close(fd);
        return 84;
    }
    buffer[bytes_read] = '\0';
    close(fd);
    return my_getnbr(buffer);
}
