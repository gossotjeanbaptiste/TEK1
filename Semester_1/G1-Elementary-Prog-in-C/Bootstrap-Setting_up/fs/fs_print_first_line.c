/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** fs_print_first_line
*/
#include <fcntl.h>
#include "../include/call.h"
#include "../include/my.h"

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[500];
    int return_integer = read(fd, buffer, 500);
    int i = 0;

    if (return_integer > 500) {
        return 84;
    }
    while (buffer[i] != '\n') {
        my_putchar(buffer[i]);
        i++;
    }
    close(fd);
    return 0;
}
