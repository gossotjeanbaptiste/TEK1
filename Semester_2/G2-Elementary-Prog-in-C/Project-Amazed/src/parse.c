/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** parse.c
*/

#include "../include/struct.h"
#include "../include/my.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int is_number(char *s)
{
    for (int i = 0; s[i]; i++)
        if (s[i] < '0' || s[i] > '9')
            return 0;
    return 1;
}

static int handle_robot(char *line, maze_t *maze, int *robots_set)
{
    if (*robots_set || !is_number(line))
        return 0;
    maze->nb_robots = my_getnbr(line);
    *robots_set = 1;
    return 1;
}

static int handle_link(maze_t *maze, char *line)
{
    char *name1 = my_strtok(line, "-");
    char *name2 = my_strtok(NULL, "-");

    if (!name1 || !name2)
        return 84;
    if (connect_rooms(maze, maze->room_list, name1, name2))
        return 84;
    return 0;
}

static int handle_room(room_list_t **list, char *line, maze_t *maze)
{
    room_t *room;
    char *name = my_strtok(line, " ");
    char *xs = my_strtok(NULL, " ");
    char *ys = my_strtok(NULL, " ");

    if (!name || !xs || !ys)
        return 84;
    room = create_room(my_strdup(name), my_getnbr(xs), my_getnbr(ys));
    if (!room || add_room_to_list(list, room))
        return 84;
    if (maze->next_is_start) {
        maze->start_name = my_strdup(name);
        maze->next_is_start = 0;
    }
    if (maze->next_is_end) {
        maze->end_name = my_strdup(name);
        maze->next_is_end = 0;
    }
    return 0;
}

static int dispatch_line(char *line,
    room_list_t **list, maze_t *maze, int *robots_set)
{
    if (handle_robot(line, maze, robots_set))
        return 0;
    if (my_strchr(line, '-') != NULL)
        return handle_link(maze, line);
    return handle_room(list, line, maze);
}

static int end_and_start_check(char *line, maze_t *maze)
{
    if (line[0] != '#')
        return 1;
    if (my_strcmp(line, "##start") == 0) {
        maze->next_is_start = 1;
        return 0;
    }
    if (my_strcmp(line, "##end") == 0) {
        maze->next_is_end = 1;
        return 0;
    }
    return 0;
}

int parse_input(maze_t *maze)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int robots_set = 0;

    do {
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';
        if (end_and_start_check(line, maze) == 0)
            continue;
        if (dispatch_line(line, &maze->room_list, maze, &robots_set) == 84)
            return 84;
    } while (1);
    free(line);
    return 0;
}
