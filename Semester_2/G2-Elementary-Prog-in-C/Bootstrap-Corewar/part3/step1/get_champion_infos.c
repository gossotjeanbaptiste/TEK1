/*
** EPITECH PROJECT, 2025
** Bootstrap-Corewar
** File description:
** get_champion_infos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include "../../include/op.h"

static int swap_endian(int num)
{
    return ((num >> 24) & 0x000000ff) |
            ((num >> 8) & 0x0000ff00) |
            ((num << 8) & 0x00ff0000) |
            ((num << 24) & 0xff000000);
}

static void show(header_t *header)
{
    header->prog_size = swap_endian(header->prog_size);
    printf("prog_name: %s\n", header->prog_name);
    printf("prog_size: %d\n", header->prog_size);
    printf("comment: %s\n", header->comment);
}

int main(int ac, char **av)
{
    int fd;
    header_t header;

    if (ac != 2) {
        fprintf(stderr, "Usage: %s <champion.cor>\n", av[0]);
        return 84;
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Cannot open file %s\n", av[1]);
        return 84;
    }
    if (read(fd, &header, sizeof(header_t)) != sizeof(header_t)) {
        fprintf(stderr, "Error: Invalid file format\n");
        close(fd);
        return 84;
    }
    close(fd);
    show(&header);
    return 0;
}
