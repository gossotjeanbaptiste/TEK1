/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** load_file_in_men
*/
#include "../include/my.h"
#include "../include/call.h"

char *load_fiile_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file_info;
    char *buffer;

    if (fd == -1)
        return (NULL);
    if (stat(filepath, &file_info) == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (file_info.st_size + 1));
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, file_info.st_size) == -1)
        return (NULL);
    buffer[file_info.st_size] = '\0';
    close(fd);
    return (buffer);
}
