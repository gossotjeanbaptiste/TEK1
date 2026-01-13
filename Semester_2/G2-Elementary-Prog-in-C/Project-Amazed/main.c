/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** main program
*/

#include "include/struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    room_list_t *rooms = NULL;
    connection_list_t *connection_list = NULL;
    maze_t maze = {0};

    maze.room_list = rooms;
    maze.connection_list = connection_list;
    if (parse_input(&maze) == 84) {
        if (!write(2, "Error: invalid input\n", 21))
            return 84;
        return 84;
    }
    print_maze(&maze);
    return 0;
}
