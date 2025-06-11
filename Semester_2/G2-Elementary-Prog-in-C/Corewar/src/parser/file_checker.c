/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** file_checker
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../../include/corewar.h"

static int get_file_size(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char buff;
    int size = 0;

    if (fd < 0)
        return -1;
    for (; read(fd, &buff, 1); size++);
    return size;
}

void verify_file(char *path, char **buffer)
{
    int size = get_file_size(path);
    int fd = open(path, O_RDONLY);
    char *buff;

    if (fd < 0)
        return;
    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        return;
    buff[size] = '\0';
    if (read(fd, buff, size) != size)
        return;
    if (!(buff[0] == 0 && buff[1] == -22 && buff[2] == -125 && buff[3] == -13))
        return;
    *buffer = buff;
}
