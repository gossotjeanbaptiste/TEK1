/*
** EPITECH PROJECT, 2024
** B-CPE-110-bssettingup-1-1-NCY-jean-baptiste.gossot
** File description:
** fs_understand_return_of_read
*/
#include "../include/call.h"
#include "../include/my.h"

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int return_integer = read(fd, buffer, size);

    if (return_integer == -1) {
        my_putstr("read failed\n");
    }
    if (return_integer == 0) {
        my_putstr("read has nothing more to read\n");
    }
    if (return_integer < size) {
        my_putstr("read didn't complete the entire buffer\n");
    }
    if (return_integer == size) {
        my_putstr("read completed the entire buffer\n");
    }
}
