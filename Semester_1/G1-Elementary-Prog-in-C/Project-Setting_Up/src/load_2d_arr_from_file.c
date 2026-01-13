/*
** EPITECH PROJECT, 2024
** Bootstrap-Setting_up
** File description:
** load_2d_arr_from_file
*/
#include "../include/call.h"
#include "../include/my.h"

char *load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
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
