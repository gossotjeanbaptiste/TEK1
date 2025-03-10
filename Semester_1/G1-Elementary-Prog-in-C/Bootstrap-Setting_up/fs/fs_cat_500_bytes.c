/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** fs_cat_500_bytes
*/
#include <unistd.h>
#include <fcntl.h>
#include "../include/call.h"
#include "../include/my.h"

void fs_cat_500_bytes(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[500];
    int return_integer = read(fd, buffer, 500);

    if (return_integer > 500) {
        return 84;
    }
    for (int i = 0; i < 500; i++) {
        write(1, &buffer[i], 1);
    }
    close(fd);
    return 0;
}
