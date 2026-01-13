/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** fs_return_of_read
*/
#include "../../include/my.h"

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    if (read(fd, buffer, size) == -1) {
        mini_printf("read failed\n");
    }
    if (read(fd, buffer, size) == 0) {
        mini_printf("read has nothing more to read\n");
    }
    if (read(fd, buffer, size) < size) {
        mini_printf("read didn't complete the entire buffer\n");
    }
    if (read(fd, buffer, size) == size) {
        mini_printf("read completed the entire buffer\n");
    }
}
