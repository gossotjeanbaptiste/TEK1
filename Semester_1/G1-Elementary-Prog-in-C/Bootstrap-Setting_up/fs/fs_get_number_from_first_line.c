/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** fs_get_number_from_first_line
*/
#include "../include/call.h"
#include "../include/my.h"
#include <fcntl.h>

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[500];
    int return_integer = read(fd, buffer, 500);
    int i = 0;
    int number = 0;

    if (return_integer == -1) {
        return 84;
    }
    while (buffer[i] != '\n') {
        number = number * 10 + buffer[i] - '0';
        i++;
    }
    close(fd);
    return number;
}
