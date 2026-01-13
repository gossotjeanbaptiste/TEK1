/*
** EPITECH PROJECT, 2025
** Day01
** File description:
** fs_cat_500_bytes
*/

#include "../../include/my.h"
#include <fcntl.h>

void fs_cat_500_bytes(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[500];
    int return_int = read(fd, buffer, 500);

    if (return_int > 500) {
        return;
    }
    for (int i = 0; i < 500; i++) {
        write(1, &buffer[i], 1);
    }
    close(fd);
    return 0;
}
